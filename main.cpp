#include"CClassData.h"
#include<iostream>
using namespace std;
int main() {
	CClassData ca("A"),cb("B");
	string de;
	char step,choose_class;
	int end = 0, i;
    string ID, Name;
    ca.nulll();
    cb.nulll();
	while (1) {
		cout <<  "Enter option: (1). Add (2). Remove (0). Exit program:";
		cin >> step;
		switch (step) {
		case '0':
			end = 1;
			break;
		case '1':
		    cout << "Select class to add to: " << "(1).Class " << ca.getClassName() << "(2).Class " << cb.getClassName() <<":";
		    cin >> choose_class;
		    if(choose_class =='A'){
                for(int j=0;j<1;j++){
                    cout << "Enter student ID: " ;
                    cin>>ID;
                    if(ca.check(ID)==1){
                        cout <<"Duplicate student ID! Please re-enter.";
                        j--;
                    }
                }
                cout << "Enter name: " ;
                cin>>Name;
                ca.length++;
                ca.add(ID,Name,"Class A");
		    }
			else if(choose_class=='B'){
                for(int j=0;j<1;j++){
                    cout << "Enter student ID: " ;
                    cin>>ID;

                    if(cb.check(ID)==1){
                        cout << "Duplicate student ID! Please re-enter.";
                        j--;
                    }
                }
                cout <<"Enter name: ";
                cin>>Name;

                cb.length++;
                cb.add(ID,Name,"Class B");
			}
            else{
                cout << "Invalid input! Please try again.\n";
            }
			break;

		case '2':
		    cout << "Select class to remove from: "  << "(1).Class " << ca.getClassName() << "(2).Class " << cb.getClassName() <<":";
		    cin >> choose_class;
		    if(choose_class =='A'){
                if(ca.getlength()==0){
                    cout<<"No data to remove."<<endl;
                    break;
                }
                else{
                    ca.Sort();
                    cout << "Enter student ID to remove:\n";
                    cin >> de;
                    ca.remove(de);
                    cout << "Updated results:" << endl;
                    ca.Sort();
                }

		    }
            else if(choose_class =='B'){
                if(cb.getlength()==0){
                    cout<< "No data to remove."<<endl;
                    break;
                }
                else{
                    cout << "Enter student ID to remove:\n";
                    cb.Sort();
                    cin >> de;
                    cb.remove(de);
                    cout <<  "Updated results:" << endl;
                cb.Sort();
                }
            }
            else{
                cout <<"Invalid input! Please try again.\n";
            }
            break;
		default:
			cout << "Invalid input! Please try again.\n";
			break;
		}
		if (end) break;
	}
	cout <<  "Results after sorting:\n";
    ca.Sort();
    cout<<endl;
	cb.Sort();
	ca.FileWrite("A");
	cb.FileWrite("B");
	system("pause");
	return 0;
}
