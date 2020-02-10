#include <iostream>;
using namespace std;
//****************************************************************************+
bool Dectection11(unsigned short num[], int elements, unsigned int width, int 
	startingposition) { //returns true if three items in array are equally space out from startingposition, else false
						//ex. [5,20,50,80] returns 1
	bool firsttrue = false;
	unsigned short distance;
	for (int j = startingposition + 1; j < elements; j++)
	{
		distance = unsigned short(num[j] - num[startingposition]);
		if (distance == width)
		{
			if (firsttrue)
			{
				return true;
			}
			else
			{
				firsttrue = true;
				startingposition = j;
			}
		}
		else if (distance > width)
		{
			firsttrue = false;
		}
	}
	return false;
}

int Dectection11EndIndex(unsigned short num[], int elements, unsigned int 
	width, int startingposition) { //returns position of ending index if 
									//three items in array are equally spaced 
									//out from startingposition, else -1
									//ex. [20,40,60] returns 2

	bool firsttrue = false; //firsttrue tracks whether or not there is an element 
							//width units away from startingindex
	unsigned short distance;
	for (int j = startingposition + 1; j < elements; j++)
	{		
		distance = unsigned short(num[j] - num[startingposition]);
		if (distance == width)
		{
			if (firsttrue) //1-1 case
			{
				return j;
			}
			else
			{			//1-? case
				firsttrue = true;
				startingposition = j;  //changes startingposition to the 
									//element width units apart from the 
									//original startingposition
			}
		}
		
	}
	return -1;
}
//****************************************************************************+
int Problem3(unsigned short num[], int elements) { //returns index where 
											//pattern begins if three items in
											//array are 20 units apart, else -1
											//ex.  [75,95,115] Returns 1
	bool firsttrue = false;
	int originalindex;
	unsigned short distance;
	for (int i = 0; i < elements; i++)
	{
		for (int j = i + 1; j < elements; j++)
		{
			distance = unsigned short(num[j] - num[i]);
			if (distance == 20)
			{
				if (firsttrue)
				{
					return originalindex;
				}
				else
				{
					firsttrue = true;
					originalindex = i;
					i = j - 1;
					break;
				}
			}
			else if (distance > 20)
			{
				firsttrue = false;
				break;
			}

		}
	}
	return -1;
}
//****************************************************************************+
int Problem4(unsigned short num[], int elements) { //returns position where 
								//pattern begins if three items in array are 20 
									//units apart and the fourth is greater than
									// 20 units away, else -1	
									//ex. [75,95,115,65496] Returns 1										
	int endindexresult;
	unsigned short distance;
	for (int i = 0; i < elements; i++)
	{
		endindexresult = Dectection11EndIndex(num, elements, 20, i);
		if (endindexresult!=-1)		////Checks for a 1-1
		{
			for (int j = endindexresult + 1; j < elements; j++)		



			{		// checks for the 0 in 1-1-0
				distance = unsigned short(num[j] - num[endindexresult]);
				if (distance == 20)
				{
					break; //Breaks if 1-1-1
				}
				else if (distance > 20)
				{
					return i; //Sucessfully found 1-1-0
				}
			}
		}
	}
	return -1;
}
//****************************************************************************+
int Problem5(unsigned short num[], int elements, unsigned int width){
	int endindexresult;
	unsigned short distance;
	for (int i = 0; i < elements; i++)
	{
		endindexresult = Dectection11EndIndex(num, elements, width, i);	
		if (endindexresult != -1) //Checks for a 1-1
		{
			for (int j = endindexresult + 1; j < elements; j++)				
			{				// checks for the 0 in 1-1-0
				distance = unsigned short(num[j] - num[endindexresult]);
				if (distance == width)
				{
					break; //breaks in the case of 1-1-1
				}
				else if (distance > width)
				{
					return i; //returned if 1-1-0
				}
			}
		}
	}
	return -1;
}

//****************************************************************************+
int Problem6(unsigned short num[], int elements, unsigned int width) {												
	int endindexresult;
	unsigned short distance;
	for (int i = 0; i < elements; i++)
	{
		endindexresult = Dectection11EndIndex(num, elements, width, i);	
		if (endindexresult != -1)	//Checks for a 1-1
		{
			for (int j = endindexresult + 1; j < elements; j++)				
			{		// checks for the 0 in 1-1-0
				distance = unsigned short(num[j] - num[endindexresult]);
				if (distance == width)
				{
					break;
				}
				else if (distance > width)
				{
					return i;
				}
			}
		}
	}
	return -1;
}

//****************************************************************************+
int main() {


	unsigned short myarray[9] = { 0, 75, 80, 85, 95, 100, 115, 65496, 65516 }; 
	int mysize = 9;
	unsigned short aarray[8] = { 0,20,25,30,45,55,60,100 }; //110
	int asize = 8;
	unsigned short barray[8] = { 65535, 9, 14, 19, 30, 45, 55,99 }; //110 and wrap
	int bsize = 8;
	unsigned short carray[7] = { 0, 20, 30, 40, 50, 60, 101 }; // 111 and 110
	int csize = 7;
	unsigned short darray[9] = { 65526, 1, 7, 10, 30, 35, 50, 70, 94}; //111,110, and wrap
	int dsize = 9;
	unsigned short earray[5] = { 65526, 10, 11, 15,17}; //1-1-?
	int esize = 5;
	cout << Dectection11EndIndex(myarray,mysize, 20, 1) << endl; //returns 6




	cout << Problem3(myarray, mysize) << endl; // 75,95,115: Returns 1
	cout << Problem4(myarray, mysize) << endl; // 75,95,115,65496: Returns 1
	cout << Problem5(aarray, asize, 15) << endl; //30,45,60,100: Returns 3
	cout << Problem6(barray, bsize, 10) << endl; //65535,9,19: Returns 0
	cout << Problem6(carray, csize, 20) << endl; //20,40,60,101: Returns 1
	cout << Problem6(darray, dsize, 20) << endl; //30,50,70,94: Returns 4
	cout << Problem6(earray, esize, 20) << endl; //65526,10,??: Returns -1
	return 0;
}