#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector <vector<int> > FillMatrix(int r, int c) {
	vector <vector<int> > Vec1;
	int x;
	for (int i = 0; i < r; i++) {
		vector<int> v;
		for (int j = 0; j < c; j++) {
			cout<<"give me number";
			cin>>x;
			v.push_back(x);
		}

		// push back above one-dimensional vector
		Vec1.push_back(v);
	}
	return Vec1;
}


void myfunction (int i) {  // function:
	std::cout << i<<' ';
}


void myfunctionvec (vector<int> v) {  // function:
	for_each(v.begin(),v.end(),myfunction);
	cout<<endl;
}


vector <vector<int> > Multiply(vector <vector<int> > Vec1,vector <vector<int> > Vec2) {
	int r1=Vec1.size();
	int c1=Vec1[0].size();
	int c2=Vec2[0].size();

	vector <vector<int> > C;
	for ( int i = 0; i <r1; i++) {
		vector<int> v;

		for (int j = 0; j < c2; j++) {
			int val=0;
			for (int k=0; k<c1; k++) {

				val+= Vec1[i][k]*Vec2[k][j];

			}

			v.push_back(val);

		}
		C.push_back(v);

	}
	return C;
}



int main() {

	vector <vector<int> > Vec1, Vec2,C;

    //ask for row cols from user
	int r1,c1,r2,c2;

	cout<<"Give matrix 1 dimensions"<<endl;
	cin>>r1>>c1;

	do {
		cout<<"Pay attention!"<<endl;
		cout<<"Give matrix 2 dimensions"<<endl;
		cin>>r2>>c2;
	} while(r2!=c1);

	cout<<"Fill Vec1"<<endl;
	Vec1=FillMatrix( r1,  c1);

	cout<<"Fill Vec2"<<endl;
	Vec2=FillMatrix(r2,c2);

    //print vec 1
	cout<< "matrix 1"<<endl;
	for_each(Vec1.begin(),Vec1.end(),myfunctionvec);

    //print vec 2
	cout<< "matrix 2"<<endl;
	for_each(Vec2.begin(),Vec2.end(),myfunctionvec);

    //multiplication
	C=Multiply(Vec1,Vec2);

    //Print result
	cout<<"Result"<<endl;
	for_each(C.begin(),C.end(),myfunctionvec);

	return 0;

}