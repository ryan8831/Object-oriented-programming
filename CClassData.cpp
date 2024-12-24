#include"CClassData.h"
#include<iostream>
#include <fstream>
CClassData::CClassData(string c){
    ClassName=c;
    length=0;
}
string CClassData ::getClassName(){
    return ClassName;
}
int CClassData ::getlength(){
    return length;
}
void CClassData :: nulll(){
    for(int i=0;i<100;i++){
        lpsdata[i]=NULL;
    }
}
void CClassData ::add(string SID, string SName, string SClass) {
		StudentData* s = new StudentData();
		s->SID = SID;
		s->SName= SName;
		s->SClass= SClass;
		for (int i = 0; i < 100; i++) {
			if (lpsdata[i] == NULL) {
				lpsdata[i] = s;
				break;
			}
		}
	}
	void CClassData ::remove(string SID) {
		int x;
        for(int i=0;i<length;i++){
        x=strcmp(SID.c_str(),lpsdata[i]->SID.c_str());
        if (x==0){
            delete lpsdata[i];
            lpsdata[i] = NULL;
            length--;
            for (int j = i; j < 99; j++)
                lpsdata[j] = lpsdata[j + 1];
            return;
            }
        }
        cout << "\n";
		return;

	}
	void CClassData ::Sort() {
        for (int i = 0; i < length-1; i++) {
            if (lpsdata[i] == NULL) continue;
            for (int j = i + 1; j < length; j++) {
                if (lpsdata[j] == NULL) continue;
                if (strcmp(lpsdata[i]->SID.c_str(), lpsdata[j]->SID.c_str()) > 0) {
                    StudentData*s = lpsdata[i];
                    lpsdata[i] = lpsdata[j];
                    lpsdata[j] =s;
                }
            }
        }
        Show();
	}
	void CClassData ::Show() {
	    cout << "<<Class" << this->getClassName() << ">>" << endl;
		printf("%s %18s %20s %19s \n","Index", "Student ID", "Name", "Class");
		for (int i = 0; i < length; i++) {
			if (lpsdata[i] == NULL)  continue;
		    printf("[%d] %20s %20s %20s \n",i+1,lpsdata[i]->SID.c_str(),lpsdata[i]->SName.c_str(),lpsdata[i]->SClass.c_str());
		}
	}
	int  CClassData ::check(string SID) {
        int checkflag=0;
        if(length>0){
            for(int i=0;i<length;i++){
                if(SID==lpsdata[i]->SID){
                    checkflag++;
                }
            }
            if(checkflag!=0){
                return 1;
            }
            else{
                return 0;
            }
        }
        else{
            return 0;
        }
    }
    void CClassData::FileWrite(string fileName) {
    	string cla=fileName;
    if(cla=="A"){
	
	fstream fout("Class_A_Students.txt",ios::app);
    if(fout.is_open()){
	
    for (int i = 0; i < length; i++) {
			if (lpsdata[i] == NULL)  continue;
		
		fout<<lpsdata[i]->SClass<<"\t";
		fout<<lpsdata[i]->SID<<"\t";
		fout<<lpsdata[i]->SName<<"\t"<<endl;
		}	
		cout<<" Data for Class A saved successfully"<<endl;
	}
		else cout<<"Failed to open file for Class A."<<endl; 
         
    fout.close();
    	

}
if(cla=="B"){
	
	fstream fout("Class_B_Students.txt",ios::app);
    if(fout.is_open()){
	
    for (int i = 0; i < length; i++) {
			if (lpsdata[i] == NULL)  continue;
		
		fout<<lpsdata[i]->SClass<<"\t";
		fout<<lpsdata[i]->SID<<"\t";
		fout<<lpsdata[i]->SName<<"\t"<<endl;
		}	
		cout<<"Data for Class B saved successfully."<<endl;
	}
		else cout<< "Failed to open file for Class B."<<endl; 
         
    fout.close();
    	

}
}

