#include<iostream>
#include<conio.h>
#include<fstream>
#include "cStack.h"
using std::string;



class myFileHanding{
    string str="";
    static string giveString();
    circularStack cstack;
public:
    void insert();
    void append();
    void update();
    void save();
    void undo();
    void push();
    void print();
    void del();
    int search(string);
};

void by(){
std::cout<<"        _"<<std::endl;
std::cout<<"       /(|"<<std::endl;
std::cout<<"      (  :"<<std::endl;
std::cout<<"     __\  \  _____"<<std::endl;
std::cout<<"   (____)  `|"<<std::endl;
std::cout<<"  (____)|   |"<<std::endl;
std::cout<<"   (____).__|"<<std::endl;
std::cout<<"    (___)__.|_____"<<std::endl;
}

string myFileHanding::giveString(){
    string buffer;
    while (true)
    {
        if (kbhit())
        {
            char ch =_getch();
            if(ch=='`'){
                std::cout<<std::endl;
                break;
            }else if(ch=='\r'){
                std::cout<<std::endl;
                buffer+='\n';
                continue;
            }else if(ch=='\b'){
                buffer.pop_back();
                std::cout<<ch;
            }else{
                buffer+=ch;
                std::cout<<ch;
            }

        }
    }
    return buffer;
}

void myFileHanding::insert(){
        std::cout<<"Enter data you want to enter"<<std::endl;
        this->push();
        this->str=giveString();
        std::cout<<std::endl<<"New string created:"<<std::endl<<std::endl;
        std::cout<<this->str<<std::endl<<std::endl;
}

void myFileHanding::append(){
    this->push();
    string toAppend=myFileHanding::giveString();
    this->str+=toAppend;
    std::cout<<"String is appended";
}

void myFileHanding::update(){
    std::cout<<"Where you want to search(Enter word)"<<std::endl;
    string wordToSearch;std::cin>>wordToSearch;
    int index=this->search(wordToSearch);
    string wordToEnter;std::cin>>wordToEnter;

    if(index==-1){
        std::cout<<"Word Not Found"<<std::endl<<std::endl;
        return;
    }

    string result;

    if(index==0){
        result=wordToEnter;
        result+=' ';
        result+=this->str;
    }else{
        result=this->str.substr(0,index);
        result+=wordToEnter;
        result+=' ';
        result+=this->str.substr(index);
    }

    this->push();
    this->str=result;
}

void myFileHanding::push(){
    this->cstack.push(this->str);
}

void myFileHanding::print(){
    std::cout<<this->str<<std::endl;
}

void myFileHanding::save(){
    string fname;
    std::cin>>fname;
    std::ofstream out(fname);
    out<<this->str;
}

void myFileHanding::undo(){
    string result=cstack.pop();
    if(result=="21212"){
        std::cout<<"Stack is empty"<<std::endl;
    }else{
        this->str=result;
    }
    std::cout<<"Undo operation successful"<<std::endl;
}

int myFileHanding::search(string toBeSearched){
    int lengthOfInternalString=this->str.size();
    if(lengthOfInternalString==0){
        return -10;
    }
    if(toBeSearched.size()==0){
        return -11;
    }


    int result=-1;
    for(int i=0;i<lengthOfInternalString;++i){
        if((toBeSearched[0]==this->str[i] && i==0)||(toBeSearched[0]==this->str[i] && str[i-1]==' ')){
            bool isMatch=true;
            int j=i;
            int k=0;
            while(k<toBeSearched.size() && j!=lengthOfInternalString){
                if(toBeSearched[k]!=this->str[j]){
                    isMatch==false;
                }
                k++;
                j++;
            }
            if(k<toBeSearched.size() && j==lengthOfInternalString){
                isMatch=false;
            }

            if(isMatch){
                result=i;
                break;
            }
        }
    }
    return result;
}

void myFileHanding::del(){
    std::cout<<"Enter word and length upto which you want to delete"<<std::endl;
    string word;std::cin>>word;
    int length;std::cin>>length;

    int index=this->search(word);

    if(index==-1){
        std::cout<<"Word Not Found"<<std::endl<<std::endl;
        return;
    }

    this->push();

    if((this->str.size()-index)<length){
        this->str=this->str.substr(0,index);
    }else{
        string result=this->str.substr(0,index);
        result+=this->str.substr(index+length);
        this->str=result;
    }
}

int main(){
   myFileHanding file;
   while (true)
   {
        //string buffer;
        std::cout<<"*******************************************************"<<std::endl;
        std::cout<<"Select Options"<<std::endl<<"i for insert"<<std::endl<<"u for update"<<std::endl<<"a for append"<<std::endl<<"s for search"<<std::endl<<"d for delete"<<std::endl<<"p for print data"<<std::endl<<"o for undo"<<std::endl<<"x for save"<<std::endl<<"e for exit"<<std::endl;
        std::cout<<"*******************************************************"<<std::endl;
        switch (getch())
        {
            case 'i':{
                std::cout<<"Insert Mode"<<std::endl<<std::endl;
                file.insert();
                break;
            }
            case 'u':{
                std::cout<<"Update Mode"<<std::endl<<std::endl;
                file.print();
                file.update();
                break;
            }
            case 'a':{
                std::cout<<"Append Mode"<<std::endl<<std::endl;
                file.append();
                break;
            }
            case 's':{
                std::cout<<"search Mode"<<std::endl<<std::endl;
                std::cout<<"Enter word you want to search"<<std::endl;
                string toBeSearched;std::cin>>toBeSearched;
                std::cout<<file.search(toBeSearched)<<std::endl<<std::endl;
                break;
            }
            case 'd':{
                std::cout<<"Delete Mode"<<std::endl<<std::endl;
                file.print();
                file.del();
                break;
            }
            case 'p':{
                std::cout<<"Printing Mode"<<std::endl<<std::endl;
                file.print();
                break;
            }
            case 'o':{
                std::cout<<"Undo Mode"<<std::endl<<std::endl;
                file.undo();
                break;
            }
            case 'x':{
                std::cout<<"Saving"<<std::endl<<std::endl;
                file.save();
                break;
            }
            case 'e':{
                std::cout<<"By By"<<std::endl<<std::endl;
                by();
                getch();
                exit(0);
            }
            case '/':{
                system("CLS");
            }
        }
   }

}
