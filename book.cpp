#include<iostream>
#include<string.h>
#include<fstream>
#include<cstdio>
#include<iomanip>
using namespace std;



class Library
{
    
    int bookid;
    char title[20];
    char author[20];
    char category[20];
    int pages;
    float addition;

    public:

    int getid(){
        return bookid;
    }

    char* gettitle() { return title; }
    char* getauthor() { return author; }
    char* getcategory() { return category; }
    float getaddition() { return addition; }

    Library()
    {
        bookid = 0;
        strcpy(title,"");
        strcpy(author,"");
        strcpy(category,"");
        pages = 0;
        addition = 0;
    }

    void getbook();
    void listviw();
    void showbook();
    void header();

} l ;

void Library :: getbook()
{
    cout<<"\nEnter Book id = ";
    cin>>bookid;
    cout<<"Enter Book Title = ";
    cin.get();
    cin.getline(title,20);
    cout<<"ENter Book Author = ";
    cin.getline(author,20);
    cout<<"Enter Book category = ";
    cin.getline(category,20);
    cout<<"Enter NO. of pages = ";
    cin>>pages;
    cout<<"Enter data of edition of Book = ";
    cin>>addition;
    cout<<endl;

}


void Library :: showbook()
{
    cout<<"\nBook ID       = "<<bookid<<endl;
    cout<<"Book Title    = "<<title<<endl;
    cout<<"Author Name   = "<<author<<endl;
    cout<<"Category      = "<<category<<endl;
    cout<<"NO of Pages   = "<<pages<<endl;
    cout<<"Eddition      = "<<addition<<endl;
}


void Library :: header()
{
    cout<<endl;
    cout.setf(ios::left);
    cout<<setw(10)<<"I.D"
        <<setw(20)<<"Book Title"
        <<setw(20)<<"Book Author"
        <<setw(15)<<"Category"
        <<setw(10)<<"Pages"
        <<setw(10)<<"Eddition"<<endl;
        for (int i = 0; i < 84; i++)
        {
         cout<<"=";
        }
        cout<<endl;
        
}


void Library:: listviw()
{
     cout.setf(ios::left);
    cout<<setw(10)<<bookid
        <<setw(20)<<title
        <<setw(20)<<author
        <<setw(15)<<category
        <<setw(10)<<pages
        <<setw(10)<<addition<<endl;
        for (int i = 0; i < 84; i++)
        {
         cout<<"=";
        }
        cout<<endl;

} 









void heading();
void addbook();
void displaybook();
void menu();
void searchmenu();

void searchbytitle();
void searchbycategory();
void searchbyauthor();
void searchbyid();
void dispose();
void modify();
void displaydisposed();









void heading()
{
   cout<<"\n\n-----------------------BOOK MANAGEMENT SYSTEM-----------------------\n\n";
        // cout<<"\n\n-=-=-=-=-=-=-=-=-=-=-=BOOK MANAGEMENT SYSTEM-=-=-=-=-=-=-=-=-=-=-=\n\n";

}


void addbook()
{
    ofstream fp;
    fp.open("books.dat",ios::app);
    l.getbook();
    fp.write((char *)&l,sizeof(l));
    cout<<"BOOK data saved.....\n";
    fp.close();

}


void displaybook()
{
    ifstream fp("books.dat");
    int rec = 0;
//    cout<<"List Of All Books........\n";
   cout<<"[ List Of All Books ]\n";
    l.header();
    while (fp.read((char *)&l,sizeof(l)))
    {
        if (rec>=0)
        {
            
            l.listviw();
            rec++;
        }
        
    }
    fp.close();
    cout<<"\nTOTAL = "<<rec<<"  Records in file....\n";
    
  

}



void searchbyid()
{
    int n, flag = 0;
    
    ifstream fp("books.dat");
    cout<<"ENter Book ID = ";
    cin.ignore();
    cin>>n;
    while (fp.read((char*)&l,sizeof(l)))
    {
        if (n==l.getid() ) 
        {
            l.showbook();
            flag++;
        }
        
    }
    fp.close();
    if (flag==0)
    {
        cout<<"\nITS is not avaialable\n";
    }
    

}

void searchbytitle()
{
    int flag = 0;
    char title[20];
    ifstream fp("books.dat");
    cout<<"ENter Book Title = ";
    cin.ignore();
    cin.getline(title,20);
    while (fp.read((char*)&l,sizeof(l)))
    {
        if ( strcmpi(title , l.gettitle())==0) 
        {
            l.showbook();
            flag++;
        }
        
    }
    fp.close();
    if (flag==0)
    {
        cout<<"\nITS is not avaialable\n";
    }
    
    
}






void searchbycategory()
{
    int flag=0,rec=0;
    char cat[20];
    ifstream fp("books.dat");
    cout<<"Enter Book Category = ";
    cin.ignore();
    cin.getline(cat,20);
       l.header();
    while (fp.read((char*)&l,sizeof(l)))
    {
        if (strcmpi(cat,l.getcategory())==0)
        {
            if (rec>=0)
            {
             
                l.listviw();
                flag++;
                rec++;
            }
            
        }
        
    }
    fp.close();
    if (flag==0)
    {
        cout<<"\nIts not available\n";
    }
    
}





void searchbyauthor()
{
    int flag=0,rec=0;
    char aut[20];
    ifstream fp("books.dat");
    cout<<"Enter Book Author = ";
    cin.ignore();
    cin.getline(aut,20);
    l.header();
                
    while (fp.read((char*)&l,sizeof(l)))
    {
        if (strcmpi(aut,l.getauthor())==0)
        {
            if (rec>=0)
            {
                l.listviw();
                flag++;
                rec++;
            }
            
        }
        
    }
    fp.close();
    if (flag==0)
    {
        cout<<"\nIts not available\n";
    }
    

}



void del(int n)
{
	fstream fp;
	fp.open("books.dat",ios::in );
	fstream fp2;
	fp2.open("temp.dat",ios::out);
	fp.seekg(0);
	while(fp.read((char *)&l,sizeof(l)))
	{
		if(l.getid()!=n)
		{
			fp2.write((char *)&l,sizeof(l));
		}
		
	}
	fp2.close();
	fp.close();
	remove("books.dat");
	rename("temp.dat","books.dat");
}




void dispose()
{
    int n,flag=0 ;
    ifstream fp("books.dat");
    ofstream fout("dispose.dat",ios::out | ios::app);
    cout<<"Enter Book ID For Deleting = ";
    cin>>n;
    while (fp.read((char*)&l,sizeof(l)))
    {
        if (n==l.getid())
        {
            l.showbook();
            flag++;
            fout.write((char *)&l,sizeof(l));
        }  
    }
    cout<<"\nBook Delete succesful..\n";
    fp.close();
    fout.close();
    if (flag==0)
    {
        cout<<"Book Number with id "<<n<<" not available..\n";
    }
    
    del(n);
		
    

}




void displaydisposed()
{
    ifstream fp("dispose.dat");
    int rec =0 ;
    cout<<"[ List Of Delete Books ]\n";
    l.header();
    while (fp.read((char*)&l,sizeof(l)))
    {
        if (rec>=0)
        {
            
            l.listviw();
            rec++;
        }
        
    }
    fp.close();
    cout<<"\nTOTAL "<<rec<<" Record in DELETE file\n";
    

}


//
//void dispose()
//{
//    int n,flag=0 ;
//    ifstream fp("books.dat");
//    ofstream fout("dispose.dat",ios::app);
//    fstream fp,fout,temp;
//    temp.open("Temp.dat" , ios::out);
//    fp.open("books.dat",ios::in);
//    fout.open("dispose.dat",ios::out |ios::app);
//    cout<<"Enter Book ID = ";
//    cin>>n;
//    while (fp.read((char*)&l,sizeof(l)))
//    {
//        if (n==l.getid())
//        {
//            l.showbook();
//            flag++;
//        
//            fout.write((char *)&l,sizeof(l));
//        }
//        
//    }
//    
//    if(flag==1){
//	
//    while (fp.read((char*)&l,sizeof(l)))
//    {
//    	 if (n!=l.getid())
//    		{
//    			temp.write((char *)&l,sizeof(l));
//			}
//	}
//	
//	}
//    temp.close();
//    fp.close();
//    fout.close();
//    remove("books.dat");
//    rename("Temp.dat","books.dat");
//    if (flag==0)
//    {
//        cout<<"Book Number with id "<<n<<" not available..\n";
//    }
//    
//
//}
//







void modify()
{
    int n ,flag = 0,pos;
    fstream fp("books.dat",ios::in | ios::out);
    cout<<"Enter Book ID = ";
    cin>>n;
    while (fp.read((char*)&l,sizeof(l)))
    {
        if (n==l.getid())
        {
            pos = fp.tellg();
            cout<<"FOllowing data...\n";
            l.showbook();
            flag++;
            fp.seekg(pos-sizeof(l));
            l.getbook();
            fp.write((char*)&l,sizeof(l));
            cout<<"\nDATA MODIFIED ...\n";
            
        }
        
        
    }
    fp.close();
    if (flag==0)
    {
        cout<<"Its not avaialable \n";
    }
    
}











void menu()
{
    int ch;
    do
    {
        heading();
        cout<<"0: EXIT.\n";
        cout<<"1: Add New Book\n";
        cout<<"2: Display All Book\n";
        cout<<"3: Search Book\n";
        cout<<"4: Delete Book\n";
        cout<<"5: Modify Details\n";
        cout<<"6: List of Delete Books\n";
        cout<<"Enter your choice = ";
        cin>>ch;
        heading();
        switch (ch)
        {
        case 1:
            addbook();
            break;
        case 2:
            displaybook();
            break;
        case 3:
            searchmenu();
            break;
        case 4:
            dispose();
            break;
        case 5:
            modify();
            break;
        case 6:
            displaydisposed();
            break;
        
        default:
            cout<<"Enter Valid number\n";
            break;
        }
    } while (ch!=0);
    
}


void searchmenu()
{
    int ch;
    do
    {
        heading();
        cout<<"BOOK SEARCH OPTION\n";
        cout<<"0: Back\n";
        cout<<"1: By ID\n";
        cout<<"2: By Title\n";
        cout<<"3: By Category\n";
        cout<<"4: By Author\n";
        cout<<"Enter Your choice = ";
        cin>>ch;
        heading();
        switch (ch)
        {
        case 1:
            searchbyid();
            break;
        case 2:
            searchbytitle();
            break;
        case 3:
            searchbycategory();
            break;
        case 4:
            searchbyauthor();
            break;
        // case 5:
        //     searchby();
        //     break;
        default:
            break;
        }




    } while (ch!=0);
    

}





int main()
{
    menu();
    // Library a;
    // a.getbook();
    // a.showbook();
    // a.header();
    // a.listviw();
    
    return 0;
}
