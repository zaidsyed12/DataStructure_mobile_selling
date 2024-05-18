#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include<time.h>//for time.
#include<windows.h>
#include <unistd.h> //sleep func
using namespace std;

class node{
public:
    string name;
    int year;
    float price;
    int qty;
	node* left;
    node* right;
    
    node(string name,int year,float price, int qty){
        this->name = name;
        this->year = year;
        this->price = price;
        this->qty = qty;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST{
public:
    node* addNode(string name, int year, float price, int qty){
            node* newNode = new node(name, year, price, qty);
            return newNode;
    }
    
    node* InsertBST(node* root, string name, int year, float price, int qty){
        if(root == NULL)
            return addNode(name, year, price,  qty);
            
        else if(name < root->name)
            root->left = InsertBST(root->left, name, year, price, qty);
            
        else if(name > root->name)
            root->right = InsertBST(root->right, name, year, price, qty);
            
        return root;
    }
    
    node* priceBST(node* root, string name, int year, float price, int qty){
        if(root == NULL)
            return addNode(name, year, price, qty);
            
        else if(price < root->price)
            root->left = priceBST(root->left, name, year, price,  qty);
            
        else if(price >= root->price)
            root->right = priceBST(root->right, name, year, price,  qty);
            
        return root;
    }
    
    node* qtyBST(node* root, string name, int year, float price, int qty){
        if(root == NULL)
            return addNode(name, year, price, qty);
            
        else if(qty < root->qty)
            root->left = qtyBST(root->left, name, year, price, qty);
            
        else if(price >= root->qty)
            root->right = qtyBST(root->right, name, year, price, qty);
            
        return root;
    }
    
    node* searchbst(node* root, string model){
		if(root==NULL ){
    		//cout<<endl<<"null";
    		fflush(stdin);
			return root;
		}
		//cout<<root->name<<endl;
		if(root->name == model){
			return root;
		}
		
		else if(model > root->name){
			return searchbst(root->right, model);
		}
		else if(model < root->name){
			return searchbst(root->left, model);
	    }
		else{
			return root;
		}
		//return root;
	}
    
	//int c=0; 
    void displayinorder(node *temp) {
        //int c=0;
		if (temp != NULL){
            displayinorder(temp->left);
            cout <<"\t"<< temp->name<<"\t";
            cout <<"Price: "<< temp->price<<"\t";
            cout <<"Year of make: "<< temp->year<<"\t";
  			cout<<"Quantity: "<< temp->qty<<endl;
            displayinorder(temp->right);
        }
        
    }
    
    
    void revInorder(node* head)
	{
    // Base case
	    if (head ==  NULL)
	        return;
	    revInorder(head->right);
	    cout <<"\t"<< head->name<<"\t";
        cout <<"Price: "<< head->price<<"\t";
        cout <<"Year of make: "<< head->year<<"\t";
        cout<<"Quantity: "<< head->qty<<endl;
	    revInorder(head->left);   
	}
    
    
};


class cxNode{
public: 
	cxNode* next;
	string c_name;
	string contact_num;
	//string p_pur;
	int t_pur;
	string password;
	
	cxNode(){
		c_name = "df";
		next = NULL;
		contact_num = "23";
		//p_pur = "df";
		t_pur = 32432;
		password = "sdg";
	}
	
	cxNode(string c_name, string contact_num, int t_pur,string password){
		this->c_name = c_name;
		this->next = NULL;
		this->contact_num = contact_num;
		//this->p_pur = p_pur;
		this->t_pur = t_pur;
		this->password = password;
	}
};

class LinkedList{
public:
	cxNode* head;
	
	LinkedList(){
		head = NULL;
	}
	
	cxNode* gethead(){
		return head;
	}
	
	void insert(string c_name, string contact_num, int t_pur, string password){
		cxNode* newNode = new cxNode( c_name, contact_num, t_pur, password);
		if(head == NULL){
			head = newNode;
			return;
		}
		
		else{
			cxNode* temp = head;
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newNode; //pointer element
		}
	}
	
	void deleteNode(cxNode* head, string uname, string pass){

    if (head == NULL) {
        cout << "Element not present in the list";
        return;
    }
    
    if ((head->c_name == uname) && (head->password == pass)) {
        cxNode* t = head;
        head = head->next; 
        
		delete (t); 
        return;
    }
    deleteNode(head->next, uname, pass);
}
	
	void print(){
		cxNode* temp = head;
		
		if(temp == NULL){
			cout << "There is no node!";
		}
		
		else{
			while(temp != NULL){
				cout << temp->c_name << endl;
				cout << temp->contact_num << endl;
				//cout << temp->p_pur << endl;
				cout << temp->t_pur << endl;
				cout << temp->password << endl;
				cout<<endl;
				temp = temp->next;
			}
		}
	}
	
	
};
	

int main()
{
    int option,opt,cn,con,num,cl,d,l,b ,y,ans,choice,i,index,select,sort,sbuy,nsearch,aftersort, f=0,userc;
	char o='n';
	string n, place,data,password,data2,model="", pass, buy,cont;
	
	node* root = NULL;
    BST samsung;
    
    int A6_p = 10000;
	int *sptr6 = &A6_p;  
	
    int A2_p = 12000;
	int *sptr2 = &A2_p;  
    
    int A8_p = 15000;
	int *sptr8 = &A8_p;  
    
    int A4_p = 20000;
	int *sptr4 = &A4_p;  
    
    int A5_p = 20000;
	int *sptr5 = &A5_p;  
    
    int A1_p = 22000;
	int *sptr1 = &A1_p;  
    
    int A7_p = 25000;
	int *sptr7 = &A7_p;  
    
    int A3_p = 25000;
	int *sptr3 = &A3_p;  
    
    int A9_p = 27000;
	int *sptr9 = &A9_p;  
    
    int qty_A6 = 5;
    int *ptrA6 = &qty_A6;
    int qty_A2 = 5;
    int *ptrA2 = &qty_A2;
    int qty_A8 = 5;
    int *ptrA8 = &qty_A8;
    int qty_A4 = 5;
    int *ptrA4 = &qty_A4;
    int qty_A5 = 5;
    int *ptrA5 = &qty_A5;
    int qty_A1 = 5;
    int *ptrA1 = &qty_A1;
    int qty_A7 = 5;
    int *ptrA7 = &qty_A7;
    int qty_A3 = 5;
    int *ptrA3 = &qty_A3;
    int qty_A9 = 5;
    int *ptrA9 = &qty_A9;
    
    
    
    root = samsung.InsertBST(root, "samsung galaxy A6", 2016, A6_p, qty_A6);
    root = samsung.InsertBST(root, "samsung galaxy A2", 2016, A2_p, qty_A2);
    root = samsung.InsertBST(root, "samsung galaxy A8", 2016, A8_p, qty_A8);
    root = samsung.InsertBST(root, "samsung galaxy A4", 2017, A4_p, qty_A4);
    root = samsung.InsertBST(root, "samsung galaxy A5", 2017, A4_p, qty_A5);
    root = samsung.InsertBST(root, "samsung galaxy A1", 2017, A1_p, qty_A1);
    root = samsung.InsertBST(root, "samsung galaxy A7", 2018, A7_p, qty_A7);
    root = samsung.InsertBST(root, "samsung galaxy A3", 2018, A3_p, qty_A3);
    root = samsung.InsertBST(root, "samsung galaxy A9", 2018, A9_p, qty_A9);    
    
    //samsung.displayinorder(root);
	//cout<<endl;
    node* root2 = NULL;
    BST iphone;
    
   int i4_p = 5000;
   int *aptr4 = &i4_p;
   int i4s_p = 9000;
   int *aptr4s = &i4s_p;
   int i5_p = 15000;
   int *aptr5 = &i5_p;
   int i5s_p = 18000;
   int *aptr5s = &i5s_p;
   int i6_p = 25000;
   int *aptr6 = &i6_p;
   int i6s_p = 80000;
   int *aptr6s = &i6s_p;
   int i7_p = 35000;
   int *aptr7 = &i7_p;
   int i7p_p = 40000;
   int *aptr7p = &i7p_p;
   int i8_p = 50000;
   int *aptr8 = &i8_p;

    int qty_i4 = 10;
    int *ptri4 = &qty_i4;
    int qty_i4s = 10;
    int *ptri4s = &qty_i4s;
    int qty_i5 = 10;
    int *ptri5 = &qty_i5;
    int qty_i5s = 10;
    int *ptri5s = &qty_i5s;
    int qty_i6 = 10;
    int *ptri6 = &qty_i6;
    int qty_i6s = 10;
    int *ptri6s = &qty_i6s;
    int qty_i7 = 10;
    int *ptri7 = &qty_i7;
    int qty_i7p = 10;
    int *ptri7p = &qty_i7p;
    int qty_i8 = 10;
    int *ptri8 = &qty_i8;
	   
	root2 = iphone.InsertBST(root2, "Iphone 4", 2010, i4_p, qty_i4);
    root2 = iphone.InsertBST(root2, "Iphone 4s", 2012, i4s_p, qty_i4s);
    root2 = iphone.InsertBST(root2, "Iphone 5", 2014, i5_p, qty_i5);
    root2 = iphone.InsertBST(root2, "Iphone 5s", 2015, i5s_p, qty_i5s);
    root2 = iphone.InsertBST(root2, "Iphone 6", 2016, i6_p, qty_i6);
    root2 = iphone.InsertBST(root2, "Iphone 6s", 2018, i6s_p, qty_i6s);
    root2 = iphone.InsertBST(root2, "Iphone 7", 2019, i7_p, qty_i7);
    root2 = iphone.InsertBST(root2, "Iphone 7 plus", 2020, i7p_p, qty_i7p);
    root2 = iphone.InsertBST(root2, "Iphone 8", 2021, i8_p, qty_i8);	
    
    //iphone.displayinorder(root2);
    //cout<<endl;
    node* root3 = NULL;
    BST huawei;
    
    int p1_p = 5000;
    int *hptr1 = &p1_p;
    int p2_p = 9000;
    int *hptr2 = &p2_p;
	int p6_p = 15000;
	int *hptr6 = &p6_p;
    int p7_p = 20000;
    int *hptr7 = &p7_p;
    int p8_p = 28000;
    int *hptr8 = &p8_p;
    int p9_p = 40000;
    int *hptr9 = &p9_p;
    int p10_p = 55000;
    int *hptr10 = &p10_p;
    int p20_p = 40000;
    int *hptr20 = &p20_p;
    int p30_p = 80000;
    int *hptr30 = &p30_p;
	
	
    int qty_p1 = 15;
    int *ptrp1 = &qty_p1;
    int qty_p2 = 15;
    int *ptrp2 = &qty_p2;
    int qty_p6 = 15;
    int *ptrp6 = &qty_p6;
    int qty_p7 = 15;
    int *ptrp7 = &qty_p7;
    int qty_p8 = 15;
    int *ptrp8 = &qty_p8;
    int qty_p9 = 15;
    int *ptrp9 = &qty_p9;
    int qty_p10 = 15;
    int *ptrp10 = &qty_p10;
    int qty_p20 = 15;
    int *ptrp20 = &qty_p20;
    int qty_p30 = 15;
    int *ptrp30 = &qty_p30;
	    
	root3 = huawei.InsertBST(root3, "Huawei P1", 2010, p1_p, qty_p1);
    root3 = huawei.InsertBST(root3, "Huawei P2", 2012, p2_p, qty_p2);
    root3 = huawei.InsertBST(root3, "Huawei P6", 2014, p6_p, qty_p6);
    root3 = huawei.InsertBST(root3, "Huawei P7", 2014, p7_p, qty_p7);
    root3 = huawei.InsertBST(root3, "Huawei P8", 2015, p8_p, qty_p8);
    root3 = huawei.InsertBST(root3, "Huawei P9", 2016, p9_p, qty_p9);
    root3 = huawei.InsertBST(root3, "Huawei P10", 2017, p10_p, qty_p10);
    root3 = huawei.InsertBST(root3, "Huawei P20", 2018, p20_p, qty_p20);
    root3 = huawei.InsertBST(root3, "Huawei P30", 2019, p30_p, qty_p30);	
    
    //huawei.displayinorder(root3);
    //cout<<endl;
    
    node* root4 = NULL;
    BST oneplus;
    
    int o6_p = 5000;
    int *optr6 = &o6_p;
    int o6t_p = 9000;
    int *optr6t = &o6t_p;
    int o7_p = 15000;
	int o7t_p = 15000;
    int *optr7t = &o7t_p;
    int o8_p = 28000;
    int *optr8 = &o8_p;
    int o8t_p = 40000;
	int *optr8t = &o8t_p;
	int o9_p = 55000;
	int *optr9 = &o9_p;  
	int o9t_p = 40000;
	int *optr9t = &o9t_p;  
	int o10_p = 80000;
	int *optr10 = &o10_p;
	
	
    int qty_o6 = 20;
    int *ptro6 = &qty_o6;
    int qty_o6t = 20;
    int *ptro6t = &qty_o6t;
    int qty_o7 = 20;
    int *ptro7 = &qty_o7;
    int qty_o7t = 20;
    int *ptro7t = &qty_o7t;
    int qty_o8 = 20;
    int *ptro8 = &qty_o8;
    int qty_o8t = 20;
    int *ptro8t = &qty_o8t;
    int qty_o9 = 20;
    int *ptro9 = &qty_o9;
    int qty_o9t = 20;
    int *ptro9t = &qty_o9t;
    int qty_o10 = 20;
    int *ptro10 = &qty_o10;
    
	    
	root4 = oneplus.InsertBST(root4, "OnePlus 6", 2010, o6_p, qty_o6);
    root4 = oneplus.InsertBST(root4, "OnePlus 6t", 2012, o6t_p, qty_o6t);
    root4 = oneplus.InsertBST(root4, "OnePlus 7", 2014, o7_p, qty_o7);
    root4 = oneplus.InsertBST(root4, "OnePlus 7t", 2014, o7t_p, qty_o7t);
    root4 = oneplus.InsertBST(root4, "OnePlus 8", 2015, o8_p, qty_o8);
    root4 = oneplus.InsertBST(root4, "OnePlus 8t", 2016, o8t_p, qty_o8t);
    root4 = oneplus.InsertBST(root4, "OnePlus 9", 2017, o9_p, qty_o9);
    root4 = oneplus.InsertBST(root4, "OnePlus 9t", 2018, o9t_p, qty_o9t);
    root4 = oneplus.InsertBST(root4, "OnePlus 10", 2019, o10_p, qty_o10);	
    
    //oneplus.displayinorder(root3);
    //cout<<endl;
    
    node* root5 = NULL;
    BST nokia;
    
    int n81_p = 12000;
    int *nptr82 = &n81_p;
    int n80_p = 14000;
    int *nptr80 = &n80_p;
    int n631_p = 15000;
	int *nptr631 = &n631_p;
	int n630_p = 14000;
	int *nptr630 = &n630_p;
	int n53_p = 2800;
	int *nptr53 = &n53_p;
	int n33_p = 4000;
	int *nptr33 = &n33_p;
	int n22_p = 5500;
	int *nptr22 = &n22_p;
	int n25_p = 40000;
	int *nptr25 = &n25_p;
	int n150_p = 80000; 
	int *nptr150 = &n150_p;
	 
	int qty_n81 = 25;
    int *ptrn81 = &qty_n81;
    int qty_n80 = 25;
    int *ptrn80 = &qty_n80;
    int qty_n631 = 25;
    int *ptrn631 = &qty_n631;
    int qty_n630 = 25;
    int *ptrn630 = &qty_n630;
    int qty_n53 = 25;
    int *ptrn853 = &qty_n53;
    int qty_n33 = 25;
    int *ptrn33 = &qty_n33;
    int qty_n22 = 25;
    int *ptrn22 = &qty_n22;
    int qty_n25 = 25;
    int *ptrn25 = &qty_n25;
    int qty_n150 = 25;
    int *ptrn150 = &qty_n150;
    
	    
	root5 = nokia.InsertBST(root5, "Nokia 8100", 2010, n81_p, qty_n81);
    root5 = nokia.InsertBST(root5, "Nokia 8000", 2012, n80_p, qty_n80);
    root5 = nokia.InsertBST(root5, "Nokia 6310", 2013, n631_p, qty_n631);
    root5 = nokia.InsertBST(root5, "Nokia 6300", 2013, n630_p, qty_n630);
    root5 = nokia.InsertBST(root5, "Nokia 5310", 2006, n53_p, qty_n53);
    root5 = nokia.InsertBST(root5, "Nokia 3310", 2008, n33_p, qty_n33);
    root5 = nokia.InsertBST(root5, "Nokia 225", 2004, n22_p, qty_n22);
    root5 = nokia.InsertBST(root5, "Nokia 250", 2018, n25_p, qty_n25);
    root5 = nokia.InsertBST(root5, "Nokia 150", 2019, n150_p, qty_n150);	
    
    //nokia.displayinorder(root5);
    //cout<<endl;
    
    node* root6 = NULL;
    BST redmi;
    
    int r8_p = 15000;
    int *rptr8 = &r8_p; 
	int r8c_p = 19000;
    int *rptr8c = &r8c_p; 
	int r9_p = 15000;
    int *rptr9 = &r9_p; 
	int r9c_p = 20000;
    int *rptr9c = &r9c_p; 
	int r10_p = 28000;
    int *rptr10 = &r10_p; 
	int r10c_p = 40000;
    int *rptr10c = &r10c_p; 
	int r11_p = 55000;
    int *rptr11 = &r11_p; 
	int r11c_p = 47000;
    int *rptr11c = &r11c_p; 
	int r12_p = 410000;
    int *rptr12 = &r12_p; 
    
    
    int qty_r8 = 30;
    int *ptrr8 = &qty_r8;
	int qty_r8c = 30;
    int *ptrr8c = &qty_r8c;
	int qty_r9 = 30;
    int *ptrr9 = &qty_r9;
	int qty_r9c = 30;
    int *ptrr9c = &qty_r9c;
	int qty_r10 = 30;
    int *ptrr10 = &qty_r10;
	int qty_r10c = 30;
    int *ptrr10c = &qty_r10c;
	int qty_r11 = 30;
    int *ptrr11 = &qty_r11;
	int qty_r11c = 30;
    int *ptrr11c = &qty_r11c;
	int qty_r12 = 30;
    int *ptrr12 = &qty_r12;
	
	    
	root6 = redmi.InsertBST(root6, "Redmi Note 8", 2009, r8_p, qty_r8);
    root6 = redmi.InsertBST(root6, "Redmi Note 8C", 2012, r8c_p, qty_r8c);
    root6 = redmi.InsertBST(root6, "Redmi Note 9", 2013, r9_p, qty_r9);
    root6 = redmi.InsertBST(root6, "Redmi Note 9C", 2018, r9c_p, qty_r9c);
    root6 = redmi.InsertBST(root6, "Redmi Note 10", 2019, r10_p, qty_r10);
    root6 = redmi.InsertBST(root6, "Redmi Note 10C", 2021, r10c_p, qty_r10c);
    root6 = redmi.InsertBST(root6, "Redmi Note 11", 2020, r11_p,  qty_r11);
    root6 = redmi.InsertBST(root6, "Redmi Note 11C", 2015, r11c_p, qty_r11c);
    root6 = redmi.InsertBST(root6, "Redmi Note 12", 2018, r12_p, qty_r12);	
    
    //redmi.displayinorder(root6);
    //cout<<endl;

	LinkedList customer;
    
	customer.insert("Haris", "03001234567", 50000, "a1");
	customer.insert("Ali","03001234568",10000,"a2");
	customer.insert("Ahmad","03211234569",20000,"a3");
	customer.insert("Taha","03001234560",230000,"a4");
	customer.insert("Hammad","03001234561",220000,"a5");
	customer.insert("Zaid","03001234562",10000,"a6");
	customer.insert("Umar","03001234563",45000,"a7");
	customer.insert("Zuhair","03001234564",43000,"a8");
	customer.insert("Rayan","03001234565",72000,"a9");
	customer.insert("Fahad","03001234566",24000,"a10");
	
    
	time_t t;  
 	time(&t);  
 	cout<<"\n\tDate and Time\n\t"<<ctime(&t); // FOR CURRENT TIME.
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN);  //text colour change.
	cout<<"\n\n\n\n\n\n\n\n\n\n\n";
	for(i=100;i<=10000;i++)
	{
		cout<<"\r\t\t\t\t\t\tLOADING.....%"<<i/100;
	}
	system("CLS");
	
	l2:
	system("CLS");
	cout<<"\n\n \t\t\t\t\t      "<<"MOBILE SELLING"<<endl<<endl;                            //FIRST PAGE 
	cout<<"\t\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<"\t\t\t\t\t    WELCOME TO THE MOBILE PALACE!"<<endl;
	cout<<"\t\t\t\t\t  ~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	jump:
	cout<<"\t\t\t Press 1 for Admin\n";
	cout<<"\t\t\t Press 2 for Customer Use\n";
	cin>>choice;
	
	if(choice == 1)
	{
		cout<<"\t\t\tEnter password\n";
		cin>>password;
		
		while(password != "21k4581")
		{
		   cout<<"\t\t\tWrong Password!!\n";
		   cout<<"\t\t\tEnter correct Password Or Press '1' to go back\n";
		   cin>>password;
		   if(password == "1")
		   {
		   	 goto jump;
		   }
		}
		
		system("CLS");
		cout<<"\t\t\t\tW  E  L  C  O  M  E\n\n";
	/*	cout<<"\t\t\t"<<"CUSTOMER DATA"<<endl<<endl;
    	
		ifstream in;
    	in.open("Customer Data.txt",ios::app);
    	//in>>data;
    	while(!in.eof())
		{
			//cxNode* head;
			getline(in,data);
			cout<<data<<endl;
        
		}
		in.close();
		
		cout<<endl<<"\t\t\t"<<"EMPLOYEE DATA"<<endl<<endl;
		
		ifstream inn;
    	inn.open("Employee Data.txt",ios::app);
    	inn>>data2;
    	while(!inn.eof())
		{
		
			getline(inn,data2);
			cout<<data2<<endl;
        
		}
	*/	
		l8:
		system("CLS");	
		int achoice;
		cout << "\n1. CUSTOMER LIST"<<endl<<"2. UPDATE PRICE"<<endl<<"3. UPDATE STOCK"<<endl<<"4. SEND PROMO"<<endl;
		
		l7:
		while(!(cin>>achoice)){
				cout<<"Error! Enter an integer"<<endl;
				cin.clear();
				cin.ignore(123, '\n');
			}
		
		switch (achoice)
		{
			case 1:
				{	
					cxNode* t1 = customer.gethead();
					
					if(t1 == NULL)
					{
						cout<<"\nNO CUSTOMER FOUND!";
					}
					else
					{
						cout<<"\nCUSTOMERS:\n";
						while(t1 != NULL)
						{
							cout<<"NAME: "<<t1->c_name<<"\tCONTACT #: "<<t1->contact_num;
							cout<<endl;
							t1 = t1->next;
						}	
					}
					int backk;
				cout<<"\n\nPRESS: 1. To return back\n";
				
				while(!(cin>>backk)){
				cout<<"Error! Enter an integer"<<endl;
				cin.clear();
				cin.ignore(123, '\n');
				}
				
				if(backk == 1)
					goto l8;
									
				}
				break;
			
			case 2:
						l3:
											
						cout<<"\t\t LIST OF AVAILABLE MOBILE BRANDS "<<endl<<endl;
						cout<<"1. Samsung"<<endl;
						cout<<"2. Iphone"<<endl;
						cout<<"3. Huwaei"<<endl;
						cout<<"4. One Plus"<<endl;
						cout<<"5. Nokia"<<endl;
						cout<<"6. Redmi"<<endl;
			
						cout<<"PRESS THE OPTION TO CHOOSE A BRAND"<<endl;
							while(!(cin>>option)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
					l1:
					cout<<endl<<"ENTER THE MODEL YOU WANT TO SEARCH"<<endl;
				
					fflush(stdin);
					getline(cin,model);
						
					if(option==1){
						if(samsung.searchbst(root, model)){
							cout<<endl<<"MODEL FOUND!"<<endl;
							node* temp = samsung.searchbst(root,model);
							int price = temp->price;
							
							cout<<"ENTER THE NEW PRICE: ";
							while(!(cin>>temp->price)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							cout<<"\nPRICE UPDATED SUCESSFULLY FROM: "<<price<<" To: "<<temp->price;
							int n;
							cout<<"\nPress 1. TO GO BACK TO MAIN PAGE Or Press 2. TO UPDATE MORE MODEL:\n";
							while(!(cin>>n)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							if(n==1)
								goto l2;
							else if(n==2)
								goto l3;
						
						}
							
						else{
						cout<<"\nNO MODEL IS NOT AVAILABLE!"<<endl;
						cout<<"ENTER THE MODEL AGAIN:";
						goto l1;					
						}
					}
					
					if(option==2){
						if(iphone.searchbst(root2, model)){
							cout<<endl<<"MODEL FOUND!"<<endl;
							node* temp = iphone.searchbst(root2,model);
							int price = temp->price;
							
							cout<<"ENTER THE NEW PRICE: ";
							while(!(cin>>temp->price)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							cout<<"\nPRICE UPDATED SUCESSFULLY FROM: "<<price<<" To: "<<temp->price;
							int n;
							cout<<"\nPress 1. TO GO BACK TO MAIN PAGE Or Press 2. TO UPDATE MORE MODEL:\n";
							while(!(cin>>n)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							if(n==1)
								goto l2;
							else if(n==2)
								goto l3;
						
						}
							
						else{
						cout<<"\nNO MODEL IS NOT AVAILABLE!"<<endl;
						cout<<"ENTER THE MODEL AGAIN:";
						goto l1;					
						}
					}
					
					if(option==3){
						if(huawei.searchbst(root3, model)){
							cout<<endl<<"MODEL FOUND!"<<endl;
							node* temp = huawei.searchbst(root3,model);
							int price = temp->price;
							
							cout<<"ENTER THE NEW PRICE: ";
							while(!(cin>>temp->price)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							cout<<"\nPRICE UPDATED SUCESSFULLY FROM: "<<price<<" To: "<<temp->price;
							int n;
							cout<<"\nPress 1. TO GO BACK TO MAIN PAGE Or Press 2. TO UPDATE MORE MODEL:\n";
							while(!(cin>>n)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							if(n==1)
								goto l2;
							else if(n==2)
								goto l3;
						
						}
							
						else{
						cout<<"\nNO MODEL IS NOT AVAILABLE!"<<endl;
						cout<<"ENTER THE MODEL AGAIN:";
						goto l1;					
						}
					}
					
					if(option==4){
						if(oneplus.searchbst(root4, model)){
							cout<<endl<<"MODEL FOUND!"<<endl;
							node* temp = oneplus.searchbst(root4,model);
							int price = temp->price;
							
							cout<<"ENTER THE NEW PRICE: ";
							while(!(cin>>temp->price)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							cout<<"\nPRICE UPDATED SUCESSFULLY FROM: "<<price<<" To: "<<temp->price;
							int n;
							cout<<"\nPress 1. TO GO BACK TO MAIN PAGE Or Press 2. TO UPDATE MORE MODEL:\n";
							while(!(cin>>n)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							if(n==1)
								goto l2;
							else if(n==2)
								goto l3;
						
						}
							
						else{
						cout<<"\nNO MODEL IS NOT AVAILABLE!"<<endl;
						cout<<"ENTER THE MODEL AGAIN:";
						goto l1;					
						}
					}
					
					if(option==5){
						if(nokia.searchbst(root5, model)){
							cout<<endl<<"MODEL FOUND!"<<endl;
							node* temp = nokia.searchbst(root5,model);
							int price = temp->price;
							
							cout<<"ENTER THE NEW PRICE: ";
							while(!(cin>>temp->price)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							cout<<"\nPRICE UPDATED SUCESSFULLY FROM: "<<price<<" To: "<<temp->price;
							int n;
							cout<<"\nPress 1. TO GO BACK TO MAIN PAGE Or Press 2. TO UPDATE MORE MODEL:\n";
							while(!(cin>>n)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							if(n==1)
								goto l2;
							else if(n==2)
								goto l3;
						
						}
							
						else{
						cout<<"\nNO MODEL IS NOT AVAILABLE!"<<endl;
						cout<<"ENTER THE MODEL AGAIN:";
						goto l1;					
						}
					}
					
					if(option==6){
						if(redmi.searchbst(root6, model)){
							cout<<endl<<"MODEL FOUND!"<<endl;
							node* temp = redmi.searchbst(root6,model);
							int price = temp->price;
							
							cout<<"ENTER THE NEW PRICE: ";
							while(!(cin>>temp->price)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							cout<<"\nPRICE UPDATED SUCESSFULLY FROM: "<<price<<" To: "<<temp->price;
							int n;
							cout<<"\nPress 1. TO GO BACK TO MAIN PAGE Or Press 2. TO UPDATE MORE MODEL:\n";
							while(!(cin>>n)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							if(n==1)
								goto l2;
							else if(n==2)
								goto l3;
						
						}
							
						else{
						cout<<"\nNO MODEL IS NOT AVAILABLE!"<<endl;
						cout<<"ENTER THE MODEL AGAIN:";
						goto l1;					
						}
					}
		
				
				break;
			case 3:
					l6:
							
						cout<<"\t\t LIST OF AVAILABLE MOBILE BRANDS "<<endl<<endl;
						cout<<"1. Samsung"<<endl;
						cout<<"2. Iphone"<<endl;
						cout<<"3. Huwaei"<<endl;
						cout<<"4. One Plus"<<endl;
						cout<<"5. Nokia"<<endl;
						cout<<"6. Redmi"<<endl;
			
						cout<<"PRESS THE OPTION TO CHOOSE A BRAND"<<endl;
							while(!(cin>>option)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
					l4:
					cout<<endl<<"ENTER THE MODEL YOU WANT TO SEARCH"<<endl;
				
					fflush(stdin);
					getline(cin,model);
						
					if(option==1){
						if(samsung.searchbst(root, model)){
							cout<<endl<<"MODEL FOUND!"<<endl;
							node* temp = samsung.searchbst(root,model);
							int quantity = temp->qty;
							
							
							cout<<"Instock:"<<quantity<<"\tENTER THE NEW QUANTITY: ";
							while(!(cin>>temp->qty)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							cout<<"\nQUANTITY UPDATED SUCESSFULLY FROM: "<<quantity<<" To: "<<temp->qty;
							int n;
							cout<<"\nPress 1. TO GO BACK TO MAIN PAGE Or Press 2. TO UPDATE MORE MODEL:\n";
							while(!(cin>>n)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							if(n==1)
								goto l2;
							else if(n==2)
								goto l6;
						
						}
							
						else{
						cout<<"\nNO MODEL IS NOT AVAILABLE!"<<endl;
						cout<<"ENTER THE MODEL AGAIN:";
						goto l4;					
						}
					}
					
					if(option==2){
						if(iphone.searchbst(root2, model)){
							cout<<endl<<"MODEL FOUND!"<<endl;
							node* temp = iphone.searchbst(root2,model);
							int quantity = temp->qty;
							
							cout<<"Instock:"<<quantity<<"\tENTER THE NEW QUANTITY: ";
							while(!(cin>>temp->qty)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
						
							cout<<"\nQUANTITY UPDATED SUCESSFULLY FROM: "<<quantity<<" To: "<<temp->qty;
							int n;
							cout<<"\nPress 1. TO GO BACK TO MAIN PAGE Or Press 2. TO UPDATE MORE MODEL:\n";
							while(!(cin>>n)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							if(n==1)
								goto l2;
							else if(n==2)
								goto l6;
						
						}
							
						else{
						cout<<"\nNO MODEL IS NOT AVAILABLE!"<<endl;
						cout<<"ENTER THE MODEL AGAIN:";
						goto l4;					
						}
					}
					if(option==3){
						if(huawei.searchbst(root3, model)){
							cout<<endl<<"MODEL FOUND!"<<endl;
							node* temp = huawei.searchbst(root3,model);
							int quantity = temp->qty;
							
							cout<<"Instock:"<<quantity<<"\tENTER THE NEW QUANTITY: ";
							while(!(cin>>temp->qty)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							cout<<"\nQUANTITY UPDATED SUCESSFULLY FROM: "<<quantity<<" To: "<<temp->qty;
							int n;
							cout<<"\nPress 1. TO GO BACK TO MAIN PAGE Or Press 2. TO UPDATE MORE MODEL:\n";
							while(!(cin>>n)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							if(n==1)
								goto l2;
							else if(n==2)
								goto l6;
						
						}
							
						else{
						cout<<"\nNO MODEL IS NOT AVAILABLE!"<<endl;
						cout<<"ENTER THE MODEL AGAIN:";
						goto l4;					
						}
					}
					if(option==4){
						if(oneplus.searchbst(root4, model)){
							cout<<endl<<"MODEL FOUND!"<<endl;
							node* temp = oneplus.searchbst(root4,model);
							int quantity = temp->qty;
							
							cout<<"Instock:"<<quantity<<"\tENTER THE NEW QUANTITY: ";
							while(!(cin>>temp->qty)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							cout<<"\nQUANTITY UPDATED SUCESSFULLY FROM: "<<quantity<<" To: "<<temp->qty;
							int n;
							cout<<"\nPress 1. TO GO BACK TO MAIN PAGE Or Press 2. TO UPDATE MORE MODEL:\n";
							while(!(cin>>n)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							if(n==1)
								goto l2;
							else if(n==2)
								goto l6;
						
						}
							
						else{
						cout<<"\nNO MODEL IS NOT AVAILABLE!"<<endl;
						cout<<"ENTER THE MODEL AGAIN:";
						goto l4;					
						}
					}
					if(option==5){
						if(nokia.searchbst(root5, model)){
							cout<<endl<<"MODEL FOUND!"<<endl;
							node* temp = nokia.searchbst(root5,model);
							int quantity = temp->qty;
							
							cout<<"Instock:"<<quantity<<"\tENTER THE NEW QUANTITY: ";
							while(!(cin>>temp->qty)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							cout<<"\nQUANTITY UPDATED SUCESSFULLY FROM: "<<quantity<<" To: "<<temp->qty;
							int n;
							cout<<"\nPress 1. TO GO BACK TO MAIN PAGE Or Press 2. TO UPDATE MORE MODEL:\n";
							while(!(cin>>n)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							if(n==1)
								goto l2;
							else if(n==2)
								goto l6;
						
						}
							
						else{
						cout<<"\nNO MODEL IS NOT AVAILABLE!"<<endl;
						cout<<"ENTER THE MODEL AGAIN:";
						goto l4;					
						}
					}
					if(option==6){
						if(redmi.searchbst(root6, model)){
							cout<<endl<<"MODEL FOUND!"<<endl;
							node* temp = redmi.searchbst(root6,model);
							int quantity = temp->qty;
							
							cout<<"Instock:"<<quantity<<"\tENTER THE NEW QUANTITY: ";
							while(!(cin>>temp->qty)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							cout<<"\nQUANTITY UPDATED SUCESSFULLY FROM: "<<quantity<<" To: "<<temp->qty;
							int n;
							cout<<"\nPress 1. TO GO BACK TO MAIN PAGE Or Press 2. TO UPDATE MORE MODEL:\n";
							while(!(cin>>n)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
							if(n==1)
								goto l2;
							else if(n==2)
								goto l6;
						
						}
							
						else{
						cout<<"\nNO MODEL IS NOT AVAILABLE!"<<endl;
						cout<<"ENTER THE MODEL AGAIN:";
						goto l4;					
						}
					}
				
				break;
			case 4:
			{
					int max_val = INT_MIN;
			
				cxNode* temp_new = customer.gethead();
				string name_cx;
				string contact_cx;
				while(temp_new != NULL)
				{
					if(max_val < temp_new->t_pur)
					{
						max_val = temp_new->t_pur;
						name_cx = temp_new->c_name;
						contact_cx = temp_new->contact_num;	
					}	
					temp_new = temp_new->next;
				}
				int var_promo;
				cout<<"\nCustomer with maximum purchse:"<<"\nName: "<<name_cx<<"\tContact Number: "<<contact_cx<<"\nHaving Total Purchase of: "<<max_val;
				cout<<"\n\nPRESS: 1. To send PROMO CODE\nPRESS: 2. To return back\n";
				
				while(!(cin>>var_promo)){
				cout<<"Error! Enter an integer"<<endl;
				cin.clear();
				cin.ignore(123, '\n');
				}
				
				if(var_promo == 1)
				{
					cout<<"\nPromo sent on his/her contact number!";
					sleep(5);
					goto l8;	
				}
				else if(var_promo == 2)
				{
					goto l8;
				}
				break;
			}
			default:
				{
					cout<<"INVALID KEY ENTERED!\n";
					cout<<"\n\t\tEnter KEY AGAIN\n";
					goto l7;	
				}
		}

	}
	
	if(choice==2){
		string uname;
		int flag=0;
		
		do{
			cout<<endl;
			cout<<"PRESS:"<<endl;
			cout<<"1. FOR SIGN UP"<<endl;
			cout<<"2. FOR LOG IN"<<endl;
			cout<<"3. TO DELETE ACCOUNT"<<endl;
			
			while(!(cin>>userc)){
				cout<<"Error! Enter an integer"<<endl;
				cin.clear();
				cin.ignore(123, '\n');
			}
			
			if(userc==3){
				cout<<"\t\tENTER USERNAME"<<endl;
				flag=0;
			
			do{
			//flag=0;
			cin>>uname;
			cxNode* user = customer.gethead();
			while(user!=NULL){
				if(user->c_name == uname){
					flag++;
				}
				user = user->next;
			}
			
			if(flag==0){
				cout<<"USERNAME DOES NOT EXIST! ENTER AGAIN"<<endl;
			}
			
		    }while(flag==0);
		    
			flag=0;
		    cout<<endl<<"ENTER PASSWORD"<<endl;
		    
		    do{
			flag=0;
			cin>>pass;
			cxNode* user = customer.gethead();
			while(user!=NULL){
				if(user->password == pass){
					flag++;
				}
				user = user->next;
			}
			
			if(flag==0){
				cout<<"INCORRECT PASSWORD! ENTER AGAIN"<<endl;
			}
			
		    }while(flag==0);
		    
		    cxNode* user = customer.gethead();
		    customer.deleteNode(user, uname, pass);
			}
			
			if(userc==2){
				cout<<"\t\tENTER USERNAME"<<endl;
				flag=0;
			
			do{
			//flag=0;
			cin>>uname;
			cxNode* user = customer.gethead();
			while(user!=NULL){
				if(user->c_name == uname){
					flag++;
				}
				user = user->next;
			}
			
			if(flag==0){
				cout<<"USERNAME DOES NOT EXIST! ENTER AGAIN"<<endl;
			}
			
		    }while(flag==0);
		    
			flag=0;
		    cout<<endl<<"ENTER PASSWORD"<<endl;
		    
		    do{
			flag=0;
			cin>>pass;
			cxNode* user = customer.gethead();
			while(user!=NULL){
				if(user->password == pass){
					flag++;
				}
				user = user->next;
			}
			
			if(flag==0){
				cout<<"INCORRECT PASSWORD! ENTER AGAIN"<<endl;
			}
			
		    }while(flag==0);
		    
		    goto afterlogin;
			}
			
			if(userc==1){
			
			cout<<"\t\tSIGN UP"<<endl;
			
			cout<<"\t\tENTER USERNAME"<<endl;
			
			do{
			flag=0;
			cin>>uname;
			cxNode* user = customer.gethead();
			while(user!=NULL){
				if(user->c_name == uname){
					flag++;
				}
				user = user->next;
			}
			
			if(flag!=0){
				cout<<"USERNAME ALREADY TAKEN! ENTER AGAIN"<<endl;
			}
			
		    }while(flag!=0);
		    
		    
		    cout<<endl<<"ENTER PASSWORD"<<endl;
		    
		    do{
			flag=0;
			cin>>pass;
			cxNode* user = customer.gethead();
			while(user!=NULL){
				if(user->password == pass){
					flag++;
				}
				user = user->next;
			}
			
			if(flag!=0){
				cout<<"PASSWORD ALREADY TAKEN! ENTER AGAIN"<<endl;
			}
			
		    }while(flag!=0);
		    
		    cout<<"ENTER CONTACT NUMBER"<<endl;
		    
		    do{
			flag=0;
			cin>>cont;
			cxNode* user = customer.gethead();
			while(user!=NULL){
				if(user->contact_num == cont){
					flag++;
				}
				user = user->next;
			}
			
			if(flag!=0){
				cout<<"CONTACT NUMBER ALREADY EXISTS! ENTER AGAIN"<<endl;
			}
			
			int len = cont.length();
			if(len!=11){
				cout<<"CONTACT NUMBER SHOULD BE OF 11 DIGITS! ENTER AGAIN"<<endl;
				flag++;
			}
			
		    }while(flag!=0);
		    
			
		    
		    //SIGN UP COMPLETE
		    viewaftersort:
		    afterlogin:	
		    system("CLS");	
			cout<<"\t\t LIST OF AVAILABLE MOBILE BRANDS "<<endl<<endl;
			cout<<"1. Samsung"<<endl;
			cout<<"2. Iphone"<<endl;
			cout<<"3. Huwaei"<<endl;
			cout<<"4. One Plus"<<endl;
			cout<<"5. Nokia"<<endl;
			cout<<"6. Redmi"<<endl;
			
			cout<<"PRESS THE OPTION TO CHOOSE A BRAND"<<endl;
			//cin>>option;
			
			while(!(cin>>option)){                                  // option -> BRANDS  // opt -> 1.view all phone  2.search phone
				cout<<"Error! Enter an integer"<<endl;
				cin.clear();
				cin.ignore(123, '\n');
			}
			
			cout<<endl<<"PRESS 1 TO VIEW ALL MOBILE'S OF THE CHOSEN BRAND"<<endl;
			cout<<"PRESS 2 TO SEARCH ANY MODEL"<<endl;
			//cin>>opt;
			
			while(!(cin>>opt)){
				cout<<"Error! Enter an integer"<<endl;
				cin.clear();
				cin.ignore(123, '\n');
			}
			
			if(opt==1){
				
				if(option==1){
					//samsung
					samsung.displayinorder(root);
				}
				
				if(option==2){
					//iphone
					iphone.displayinorder(root2);
				}
				
				if(option==3){
					//huawei
					huawei.displayinorder(root3);
				}
				
				if(option==4){
					//oneplus
					oneplus.displayinorder(root4);
				}
				
				if(option==5){
					//nokia
					nokia.displayinorder(root5);
				}
				
				if(option==6){
					//remi
					redmi.displayinorder(root6);
				}
				
			}
			
			if(opt==2){
				//searching user mobile
				cout<<endl<<"ENTER THE MODEL YOU WANT TO SEARCH"<<endl;
				
				fflush(stdin);
				getline(cin,model);
				
				if(option==1){
					if(samsung.searchbst(root, model)){
						cout<<endl<<"YES MODEL IS AVAILABLE!"<<endl;
						cout<<endl<<"DO YOU WANT TO BUY THIS MODEL? PRESS 1 FOR YES, 2 FOR NO"<<endl;
						
						while(!(cin>>sbuy)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
						
						if(sbuy==1){
							node* temp = samsung.searchbst(root,model);
							
							/////
							temp->qty = temp->qty - 1; 
							///
							system("CLS");
							cout<<endl<<"\t\t***YOUR PRODUCT***"<<endl<<endl;
							cout<<temp->name<<"\t"<<temp->price<<"\t"<<temp->year<<endl;
							cout<<endl<<"\t\t"<<"THANKS FOR SHOPPING"<<endl;
							
						}
					}
					else{
						cout<<"NO MODEL IS NOT AVAILABLE!"<<endl;
						cout<<endl<<"PRESS 1 TO VIEW ALL MOBILE'S OF THE CHOSEN BRAND"<<endl;
						cout<<"PRESS 2 TO EXIT"<<endl;
						
						while(!(cin>>nsearch)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
						
						if(nsearch==1){
							samsung.displayinorder(root);
							goto loop;
						}
					}
					
				}
				
				if(option==2){
					
					//iphone.searchbst(root2, model);
					if(iphone.searchbst(root2, model)){
						cout<<"YES MODEL IS AVAILABLE!"<<endl;
						cout<<endl<<"DO YOU WANT TO BUY THIS MODEL? PRESS 1 FOR YES, 2 FOR NO"<<endl;
						
						while(!(cin>>sbuy)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
						
						if(sbuy==1){
							node* temp = iphone.searchbst(root2,model);
							///
								temp->qty = temp->qty - 1; 
							///
							system("CLS");
							cout<<endl<<"\t\t***YOUR PRODUCT***"<<endl<<endl;
							cout<<temp->name<<"\t"<<temp->price<<"\t"<<temp->year<<endl;
							cout<<endl<<"\t\t"<<"THANKS FOR SHOPPING"<<endl;
							
						}
					}
					else{
						cout<<"NO MODEL IS NOT AVAILABLE!"<<endl;
						cout<<endl<<"PRESS 1 TO VIEW ALL MOBILE'S OF THE CHOSEN BRAND"<<endl;
						cout<<"PRESS 2 TO EXIT"<<endl;
						
						while(!(cin>>nsearch)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
						
						if(nsearch==1){
							iphone.displayinorder(root2);
							goto loop;
						}
					}
				}
				
				if(option==3){
					
					if(huawei.searchbst(root3, model)){
						cout<<"YES MODEL IS AVAILABLE!"<<endl;
						cout<<endl<<"DO YOU WANT TO BUY THIS MODEL? PRESS 1 FOR YES, 2 FOR NO"<<endl;
						
						while(!(cin>>sbuy)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
						
						if(sbuy==1){
							node* temp = huawei.searchbst(root3,model);
							
							///
								temp->qty = temp->qty - 1; 
							///
							system("CLS");
							cout<<endl<<"\t\t***YOUR PRODUCT***"<<endl<<endl;
							cout<<temp->name<<"\t"<<temp->price<<"\t"<<temp->year<<endl;
							cout<<endl<<"\t\t"<<"THANKS FOR SHOPPING"<<endl;
							
						}
					}
					else{
						cout<<"NO MODEL IS NOT AVAILABLE!"<<endl;
						cout<<endl<<"PRESS 1 TO VIEW ALL MOBILE'S OF THE CHOSEN BRAND"<<endl;
						cout<<"PRESS 2 TO EXIT"<<endl;
						
						while(!(cin>>nsearch)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
						
						if(nsearch==1){
							huawei.displayinorder(root3);
							goto loop;
						}
					}
				}
				
				if(option==4){
					
					if(oneplus.searchbst(root4, model)){
						cout<<"YES MODEL IS AVAILABLE!"<<endl;
						cout<<endl<<"DO YOU WANT TO BUY THIS MODEL? PRESS 1 FOR YES, 2 FOR NO"<<endl;
						
						while(!(cin>>sbuy)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
						
						if(sbuy==1){
							node* temp = oneplus.searchbst(root4,model);
							
							///
								temp->qty = temp->qty - 1; 
							///
							system("CLS");
							cout<<endl<<"\t\t***YOUR PRODUCT***"<<endl<<endl;
							cout<<temp->name<<"\t"<<temp->price<<"\t"<<temp->year<<endl;
							cout<<endl<<"\t\t"<<"THANKS FOR SHOPPING"<<endl;
							
						}
					}
					
					else{
						cout<<"NO MODEL IS NOT AVAILABLE!"<<endl;
						cout<<endl<<"PRESS 1 TO VIEW ALL MOBILE'S OF THE CHOSEN BRAND"<<endl;
						cout<<"PRESS 2 TO EXIT"<<endl;
						
						while(!(cin>>nsearch)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
						
						if(nsearch==1){
							oneplus.displayinorder(root4);
							goto loop;
						}
					}
				}
				
				if(option==5){
					
					if(nokia.searchbst(root5, model)){
						cout<<"YES MODEL IS AVAILABLE!"<<endl;
						cout<<endl<<"DO YOU WANT TO BUY THIS MODEL? PRESS 1 FOR YES, 2 FOR NO"<<endl;
						
						while(!(cin>>sbuy)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
						
						if(sbuy==1){
							node* temp = nokia.searchbst(root5,model);
							
							///
								temp->qty = temp->qty - 1; 
							///
							cout<<endl<<"\t\t***YOUR PRODUCT***"<<endl<<endl;
							cout<<endl<<"YOUR PRODUCT"<<endl;
							cout<<temp->name<<"\t"<<temp->price<<"\t"<<temp->year<<endl;
							cout<<endl<<"\t\t"<<"THANKS FOR SHOPPING"<<endl;
							
						}
					}
					else{
						cout<<"NO MODEL IS NOT AVAILABLE!"<<endl;
						cout<<endl<<"PRESS 1 TO VIEW ALL MOBILE'S OF THE CHOSEN BRAND"<<endl;
						cout<<"PRESS 2 TO EXIT"<<endl;
						
						while(!(cin>>nsearch)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
						
						if(nsearch==1){
							nokia.displayinorder(root5);
							goto loop;
						}
					}
				}
				
				if(option==6){
					
					if(redmi.searchbst(root6, model)){
						cout<<"YES MODEL IS AVAILABLE!"<<endl;
						cout<<endl<<"DO YOU WANT TO BUY THIS MODEL? PRESS 1 FOR YES, 2 FOR NO"<<endl;
						
						while(!(cin>>sbuy)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
						
						if(sbuy==1){
							node* temp = redmi.searchbst(root6,model);
							
							///
								temp->qty = temp->qty - 1; 
							///
							system("CLS");
							cout<<endl<<"\t\t***YOUR PRODUCT***"<<endl<<endl;
							cout<<temp->name<<"\t"<<temp->price<<"\t"<<temp->year<<endl;
							cout<<endl<<"\t\t"<<"THANKS FOR SHOPPING"<<endl;
							
						}
					}
					
					else{
						cout<<"NO MODEL IS NOT AVAILABLE!"<<endl;
						cout<<endl<<"PRESS 1 TO VIEW ALL MOBILE'S OF THE CHOSEN BRAND"<<endl;
						cout<<"PRESS 2 TO EXIT"<<endl;
						
						while(!(cin>>nsearch)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
						}
						
						if(nsearch==1){
							redmi.displayinorder(root6);
							goto loop;
						}
					}
				}
				
			}
			
			if(opt==1){                                                                       
				loop:
				cout<<"PRESS 1 FOR SORTING OPTIONS"<<endl;
				cout<<"PRESS 2 TO SELECT A MOBILE PHONE"<<endl;
				
				while(!(cin>>select)){
				cout<<"Error! Enter an integer"<<endl;
				cin.clear();
				cin.ignore(123, '\n');
			    }
				
				if(select==1){
					cout<<"PRESS 1 FOR HIGH TO LOW PRICE"<<endl;
					cout<<"PRESS 2 FOR LOW TO HIGH PRICE"<<endl;
					while(!(cin>>sort)){
				    cout<<"Error! Enter an integer"<<endl;
				    cin.clear();
				    cin.ignore(123, '\n');
					}
					
					if(sort==1){
					
					system("CLS");	
					cout<<"Phone list sorted High to Low:\n";
					
						if(option==1){
							node* root11 = NULL;
							BST samsungp;
							root11 = samsungp.priceBST(root11, "samsung galaxy A6", 2016, 10000, 5);
    						root11 = samsungp.priceBST(root11, "samsung galaxy A2", 2016, 12000, 5);
    						root11 = samsungp.priceBST(root11, "samsung galaxy A8", 2016, 15000, 5);
    						root11 = samsungp.priceBST(root11, "samsung galaxy A4", 2017, 20000, 5);
    						root11 = samsungp.priceBST(root11, "samsung galaxy A5", 2017, 20000, 5);
    						root11 = samsungp.priceBST(root11, "samsung galaxy A1", 2017, 22000, 5);
    						root11 = samsungp.priceBST(root11, "samsung galaxy A7", 2018, 25000, 5);
    						root11 = samsungp.priceBST(root11, "samsung galaxy A3", 2018, 25000, 5);
    						root11 = samsungp.priceBST(root11, "samsung galaxy A9", 2018, 27000, 5);
    						
    						samsungp.revInorder(root11);
    						cout<<"PRESS:"<<endl;
    						cout<<"1. TO SELECT A MOBILE FROM THIS LIST"<<endl;
    						cout<<"2. TO VIEW PHONE LIST AGAIN"<<endl;
    						cout<<"3. TO EXIT"<<endl;
    						
							while(!(cin>>aftersort)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
			    			}
			    			
			    			if(aftersort==1){
			    				goto ChooseAfterSort;
							}
							if(aftersort==2){
								goto viewaftersort;
							}
						}
						
						if(option==2){
							node* root12 = NULL;
							BST iphonep;
							root12 = iphonep.priceBST(root12, "Iphone 4", 2010, 5000, 10);
    						root12 = iphonep.priceBST(root12, "Iphone 4s", 2012, 9000, 10);
    						root12 = iphonep.priceBST(root12, "Iphone 5", 2014, 15000, 10);
    						root12 = iphonep.priceBST(root12, "Iphone 5s", 2015, 18000, 10);
    						root12 = iphonep.priceBST(root12, "Iphone 6", 2016, 25000, 10);
    						root12 = iphonep.priceBST(root12, "Iphone 6s", 2018, 80000, 10);
    						root12 = iphonep.priceBST(root12, "Iphone 7", 2019, 35000, 10);
    						root12 = iphonep.priceBST(root12, "Iphone 7 plus", 2020, 40000, 10);
    						root12 = iphonep.priceBST(root12, "Iphone 8", 2021, 50000, 10);
    						
    						iphonep.revInorder(root12);
    						cout<<"PRESS:"<<endl;
    						cout<<"1. TO SELECT A MOBILE FROM THIS LIST"<<endl;
    						cout<<"2. TO VIEW PHONE LIST AGAIN"<<endl;
    						cout<<"3. TO EXIT"<<endl;
    						
							while(!(cin>>aftersort)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
			    			}
			    			
			    			if(aftersort==1){
			    				goto ChooseAfterSort;
							}
							if(aftersort==2){
								goto viewaftersort;
							}
						}
						if(option==3){
							node* root13 = NULL;
    						BST huaweip;
	    
							root13 = huaweip.priceBST(root13, "Huawei P1", 2010, 5000, 15);
    						root13 = huaweip.priceBST(root13, "Huawei P2", 2012, 9000, 15);
    						root13 = huaweip.priceBST(root13, "Huawei P6", 2014, 15000, 15);
    						root13 = huaweip.priceBST(root13, "Huawei P7", 2014, 20000, 15);
    						root13 = huaweip.priceBST(root13, "Huawei P8", 2015, 28000, 15);
    						root13 = huaweip.priceBST(root13, "Huawei P9", 2016, 40000, 15);
    						root13 = huaweip.priceBST(root13, "Huawei P10", 2017, 55000, 15);
    						root13 = huaweip.priceBST(root13, "Huawei P20", 2018, 40000, 15);
    						root13 = huaweip.priceBST(root13, "Huawei P30", 2019, 80000, 15);
							
							huaweip.revInorder(root13);	
							
							cout<<"PRESS:"<<endl;
    						cout<<"1. TO SELECT A MOBILE FROM THIS LIST"<<endl;
    						cout<<"2. TO VIEW PHONE LIST AGAIN"<<endl;
    						cout<<"3. TO EXIT"<<endl;
    						
							while(!(cin>>aftersort)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
			    			}
			    			
			    			if(aftersort==1){
			    				goto ChooseAfterSort;
							}
							if(aftersort==2){
								goto viewaftersort;
							}
						}
						
						if(option==4){
							node* root14 = NULL;
    						BST oneplusp;
	    
							root14 = oneplusp.priceBST(root14, "OnePlus 6", 2010, o6_p, qty_o6);
    						root14 = oneplusp.priceBST(root14, "OnePlus 6t", 2012, o6t_p, qty_o6t);
    						root14 = oneplusp.priceBST(root14, "OnePlus 7", 2014, o7_p, qty_o7);
    						root14 = oneplusp.priceBST(root14, "OnePlus 7t", 2014, o7t_p, qty_o7t);
    						root14 = oneplusp.priceBST(root14, "OnePlus 8", 2015, o8_p, qty_o8);
    						root14 = oneplusp.priceBST(root14, "OnePlus 8t", 2016, o8t_p, qty_o8t);
    						root14 = oneplusp.priceBST(root14, "OnePlus 9", 2017, o9_p, qty_o9);
    						root14 = oneplusp.priceBST(root14, "OnePlus 9t", 2018, o9t_p, qty_o9t);
    						root14 = oneplusp.priceBST(root14, "OnePlus 10", 2019, o10_p, qty_o10);
							
							oneplusp.revInorder(root14);	
							
							cout<<"PRESS:"<<endl;
    						cout<<"1. TO SELECT A MOBILE FROM THIS LIST"<<endl;
    						cout<<"2. TO VIEW PHONE LIST AGAIN"<<endl;
    						cout<<"3. TO EXIT"<<endl;
    						
							while(!(cin>>aftersort)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
			    			}
			    			
			    			if(aftersort==1){
			    				goto ChooseAfterSort;
							}
							if(aftersort==2){
								goto viewaftersort;
							}
						}
						
						if(option==5){
							
							node* root15 = NULL;
    						BST nokiap;
							
							root15 = nokiap.priceBST(root15, "Nokia 8100", 2010, n81_p, qty_n81);
    						root15 = nokiap.priceBST(root15, "Nokia 8000", 2012, n80_p, qty_n80);
    						root15 = nokiap.priceBST(root15, "Nokia 6310", 2013, n631_p, qty_n631);
    						root15 = nokiap.priceBST(root15, "Nokia 6300", 2013, n630_p, qty_n630);
    						root15 = nokiap.priceBST(root15, "Nokia 5310", 2006, n53_p, qty_n53);
    						root15 = nokiap.priceBST(root15, "Nokia 3310", 2008, n33_p, qty_n33);
    						root15 = nokiap.priceBST(root15, "Nokia 225", 2004, n22_p, qty_n22);
    						root15 = nokiap.priceBST(root15, "Nokia 250", 2018, n25_p, qty_n25);
    						root15 = nokiap.priceBST(root15, "Nokia 150", 2019, n150_p, qty_n150);
							
							nokiap.revInorder(root15);	
							
							cout<<"PRESS:"<<endl;
    						cout<<"1. TO SELECT A MOBILE FROM THIS LIST"<<endl;
    						cout<<"2. TO VIEW PHONE LIST AGAIN"<<endl;
    						cout<<"3. TO EXIT"<<endl;
    						
							while(!(cin>>aftersort)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
			    			}
			    			
			    			if(aftersort==1){
			    				goto ChooseAfterSort;
							}
							if(aftersort==2){
								goto viewaftersort;
							}	
						}
						
						if(option==6){
							
							node* root16 = NULL;
    						BST redmip;
    						
    						root16 = redmip.priceBST(root16, "Redmi Note 8", 2009, r8_p, qty_r8);
    						root16 = redmip.priceBST(root16, "Redmi Note 8C", 2012, r8c_p, qty_r8c);
    						root16 = redmip.priceBST(root16, "Redmi Note 9", 2013, r9_p, qty_r9);
    						root16 = redmip.priceBST(root16, "Redmi Note 9C", 2018, r9c_p, qty_r9c);
    						root16 = redmip.priceBST(root16, "Redmi Note 10", 2019, r10_p, qty_r10);
    						root16 = redmip.priceBST(root16, "Redmi Note 10C", 2021, r10c_p, qty_r10c);
    						root16 = redmip.priceBST(root16, "Redmi Note 11", 2020, r11_p,  qty_r11);
    						root16 = redmip.priceBST(root16, "Redmi Note 11C", 2015, r11c_p, qty_r11c);
    						root16 = redmip.priceBST(root16, "Redmi Note 12", 2018, r12_p, qty_r12);	
    						
    						redmip.revInorder(root16);	
							
							cout<<"PRESS:"<<endl;
    						cout<<"1. TO SELECT A MOBILE FROM THIS LIST"<<endl;
    						cout<<"2. TO VIEW PHONE LIST AGAIN"<<endl;
    						cout<<"3. TO EXIT"<<endl;
    						
							while(!(cin>>aftersort)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
			    			}
			    			
			    			if(aftersort==1){
			    				goto ChooseAfterSort;
							}
							if(aftersort==2){
								goto viewaftersort;
							}
						}
						
						
					}
					
					if(sort==2){
					
						system("CLS");
						cout<<"Phone list sorted Low to High :\n";
					
						if(option==1){
							
							node* root11 = NULL;
							BST samsungp;
							root11 = samsungp.priceBST(root11, "samsung galaxy A6", 2016, 10000, 5);
    						root11 = samsungp.priceBST(root11, "samsung galaxy A2", 2016, 12000, 5);
    						root11 = samsungp.priceBST(root11, "samsung galaxy A8", 2016, 15000, 5);
    						root11 = samsungp.priceBST(root11, "samsung galaxy A4", 2017, 20000, 5);
    						root11 = samsungp.priceBST(root11, "samsung galaxy A5", 2017, 20000, 5);
    						root11 = samsungp.priceBST(root11, "samsung galaxy A1", 2017, 22000, 5);
    						root11 = samsungp.priceBST(root11, "samsung galaxy A7", 2018, 25000, 5);
    						root11 = samsungp.priceBST(root11, "samsung galaxy A3", 2018, 25000, 5);
    						root11 = samsungp.priceBST(root11, "samsung galaxy A9", 2018, 27000, 5);
    						
    						samsungp.displayinorder(root11);
    						
    						cout<<"PRESS:"<<endl;
    						cout<<"1. TO SELECT A MOBILE FROM THIS LIST"<<endl;
    						cout<<"2. TO VIEW PHONE LIST AGAIN"<<endl;
    						cout<<"3. TO EXIT"<<endl;
    						
							while(!(cin>>aftersort)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
			    			}
			    			
			    			if(aftersort==1){
			    				goto ChooseAfterSort;
							}
							if(aftersort==2){
								goto viewaftersort;
							}
							
						}
						
						if(option==2){
							node* root12 = NULL;
							BST iphonep;
							root12 = iphonep.priceBST(root12, "Iphone 4", 2010, 5000, 10);
    						root12 = iphonep.priceBST(root12, "Iphone 4s", 2012, 9000, 10);
    						root12 = iphonep.priceBST(root12, "Iphone 5", 2014, 15000, 10);
    						root12 = iphonep.priceBST(root12, "Iphone 5s", 2015, 18000, 10);
    						root12 = iphonep.priceBST(root12, "Iphone 6", 2016, 25000, 10);
    						root12 = iphonep.priceBST(root12, "Iphone 6s", 2018, 80000, 10);
    						root12 = iphonep.priceBST(root12, "Iphone 7", 2019, 35000, 10);
    						root12 = iphonep.priceBST(root12, "Iphone 7 plus", 2020, 40000, 10);
    						root12 = iphonep.priceBST(root12, "Iphone 8", 2021, 50000, 10);
							
							iphonep.displayinorder(root12);	
							
							cout<<"PRESS:"<<endl;
    						cout<<"1. TO SELECT A MOBILE FROM THIS LIST"<<endl;
    						cout<<"2. TO VIEW PHONE LIST AGAIN"<<endl;
    						cout<<"3. TO EXIT"<<endl;
    						
							while(!(cin>>aftersort)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
			    			}
			    			
			    			if(aftersort==1){
			    				goto ChooseAfterSort;
							}
							if(aftersort==2){
								goto viewaftersort;
							}
						}
						
						if(option==3){
							node* root13 = NULL;
    						BST huaweip;
	    
							root13 = huaweip.priceBST(root13, "Huawei P1", 2010, 5000, 15);
    						root13 = huaweip.priceBST(root13, "Huawei P2", 2012, 9000, 15);
    						root13 = huaweip.priceBST(root13, "Huawei P6", 2014, 15000, 15);
    						root13 = huaweip.priceBST(root13, "Huawei P7", 2014, 20000, 15);
    						root13 = huaweip.priceBST(root13, "Huawei P8", 2015, 28000, 15);
    						root13 = huaweip.priceBST(root13, "Huawei P9", 2016, 40000, 15);
    						root13 = huaweip.priceBST(root13, "Huawei P10", 2017, 55000, 15);
    						root13 = huaweip.priceBST(root13, "Huawei P20", 2018, 40000, 15);
    						root13 = huaweip.priceBST(root13, "Huawei P30", 2019, 80000, 15);
							
							huaweip.displayinorder(root13);	
							
							cout<<"PRESS:"<<endl;
    						cout<<"1. TO SELECT A MOBILE FROM THIS LIST"<<endl;
    						cout<<"2. TO VIEW PHONE LIST AGAIN"<<endl;
    						cout<<"3. TO EXIT"<<endl;
    						
							while(!(cin>>aftersort)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
			    			}
			    			
			    			if(aftersort==1){
			    				goto ChooseAfterSort;
							}
							if(aftersort==2){
								goto viewaftersort;
							}
						}
						
						if(option==4){
							node* root14 = NULL;
    						BST oneplusp;
	    
							root14 = oneplusp.priceBST(root14, "OnePlus 6", 2010, o6_p, qty_o6);
    						root14 = oneplusp.priceBST(root14, "OnePlus 6t", 2012, o6t_p, qty_o6t);
    						root14 = oneplusp.priceBST(root14, "OnePlus 7", 2014, o7_p, qty_o7);
    						root14 = oneplusp.priceBST(root14, "OnePlus 7t", 2014, o7t_p, qty_o7t);
    						root14 = oneplusp.priceBST(root14, "OnePlus 8", 2015, o8_p, qty_o8);
    						root14 = oneplusp.priceBST(root14, "OnePlus 8t", 2016, o8t_p, qty_o8t);
    						root14 = oneplusp.priceBST(root14, "OnePlus 9", 2017, o9_p, qty_o9);
    						root14 = oneplusp.priceBST(root14, "OnePlus 9t", 2018, o9t_p, qty_o9t);
    						root14 = oneplusp.priceBST(root14, "OnePlus 10", 2019, o10_p, qty_o10);
							
							oneplusp.displayinorder(root14);	
							
							cout<<"PRESS:"<<endl;
    						cout<<"1. TO SELECT A MOBILE FROM THIS LIST"<<endl;
    						cout<<"2. TO VIEW PHONE LIST AGAIN"<<endl;
    						cout<<"3. TO EXIT"<<endl;
    						
							while(!(cin>>aftersort)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
			    			}
			    			
			    			if(aftersort==1){
			    				goto ChooseAfterSort;
							}
							if(aftersort==2){
								goto viewaftersort;
							}
						}
						
						if(option==5){
							
							node* root15 = NULL;
    						BST nokiap;
							
							root15 = nokiap.priceBST(root15, "Nokia 8100", 2010, n81_p, qty_n81);
    						root15 = nokiap.priceBST(root15, "Nokia 8000", 2012, n80_p, qty_n80);
    						root15 = nokiap.priceBST(root15, "Nokia 6310", 2013, n631_p, qty_n631);
    						root15 = nokiap.priceBST(root15, "Nokia 6300", 2013, n630_p, qty_n630);
    						root15 = nokiap.priceBST(root15, "Nokia 5310", 2006, n53_p, qty_n53);
    						root15 = nokiap.priceBST(root15, "Nokia 3310", 2008, n33_p, qty_n33);
    						root15 = nokiap.priceBST(root15, "Nokia 225", 2004, n22_p, qty_n22);
    						root15 = nokiap.priceBST(root15, "Nokia 250", 2018, n25_p, qty_n25);
    						root15 = nokiap.priceBST(root15, "Nokia 150", 2019, n150_p, qty_n150);
							
							nokiap.displayinorder(root15);	
							
							cout<<"PRESS:"<<endl;
    						cout<<"1. TO SELECT A MOBILE FROM THIS LIST"<<endl;
    						cout<<"2. TO VIEW PHONE LIST AGAIN"<<endl;
    						cout<<"3. TO EXIT"<<endl;
    						
							while(!(cin>>aftersort)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
			    			}
			    			
			    			if(aftersort==1){
			    				goto ChooseAfterSort;
							}
							if(aftersort==2){
								goto viewaftersort;
							}	
						}
						
						if(option==6){
							
							node* root16 = NULL;
    						BST redmip;
    						
    						root16 = redmip.priceBST(root16, "Redmi Note 8", 2009, r8_p, qty_r8);
    						root16 = redmip.priceBST(root16, "Redmi Note 8C", 2012, r8c_p, qty_r8c);
    						root16 = redmip.priceBST(root16, "Redmi Note 9", 2013, r9_p, qty_r9);
    						root16 = redmip.priceBST(root16, "Redmi Note 9C", 2018, r9c_p, qty_r9c);
    						root16 = redmip.priceBST(root16, "Redmi Note 10", 2019, r10_p, qty_r10);
    						root16 = redmip.priceBST(root16, "Redmi Note 10C", 2021, r10c_p, qty_r10c);
    						root16 = redmip.priceBST(root16, "Redmi Note 11", 2020, r11_p,  qty_r11);
    						root16 = redmip.priceBST(root16, "Redmi Note 11C", 2015, r11c_p, qty_r11c);
    						root16 = redmip.priceBST(root16, "Redmi Note 12", 2018, r12_p, qty_r12);	
    						
    						redmip.displayinorder(root16);	
							
							cout<<"PRESS:"<<endl;
    						cout<<"1. TO SELECT A MOBILE FROM THIS LIST"<<endl;
    						cout<<"2. TO VIEW PHONE LIST AGAIN"<<endl;
    						cout<<"3. TO EXIT"<<endl;
    						
							while(!(cin>>aftersort)){
							cout<<"Error! Enter an integer"<<endl;
							cin.clear();
							cin.ignore(123, '\n');
			    			}
			    			
			    			if(aftersort==1){
			    				goto ChooseAfterSort;
							}
							if(aftersort==2){
								goto viewaftersort;
							}
						}
						
				    }
			    }
			    
				if(select==2){                                                               // option -> BRANDS  // opt -> 1.view all phone  2.search phone  //  select -> 1. sorting  2.select phone
					
					ChooseAfterSort:
					cout<<"ENTER THE PHONE YOU WANT TO BUY"<<endl;
					fflush(stdin);
					getline(cin,buy);
					do{
						flag=0;
						//cin>>buy;
						
						// SAMSUNG SEARCHING
						if(option==1){
						if(samsung.searchbst(root, buy)){     
						flag=1;
						node* temp = samsung.searchbst(root,buy);
						//
						system("CLS");
						//
						cout<<endl<<"\t\t***YOUR PRODUCT***"<<endl<<endl;
						cout<<temp->name<<"\t"<<temp->price<<"\t"<<temp->year<<endl;
						cout<<endl<<"\t\t"<<"THANKS FOR SHOPPING"<<endl<<endl<<endl;
						if(userc==1){
							customer.insert(uname, cont, temp->price ,pass);    
							
							ofstream writefile;
							writefile.open("buyers12.txt", ios::in);
							if(!writefile){
								cout<<"File could not be opened."<<endl;
								exit(1);
							}
							else{
								cxNode* temp2 = customer.gethead();
								while(temp2->next!=NULL){
									writefile << temp2->c_name << " \t" << temp2->password << " \t" << temp2->contact_num <<"\t"<<temp2->t_pur<<endl;
									temp2 = temp2->next;
								}
								writefile << temp2->c_name << " \t" << temp2->password << " \t" << temp2->contact_num <<"\t"<<temp2->t_pur<<endl;
							}
							writefile.close();		
									
						}
						
						if(userc==2){
							cxNode* temp2 = customer.gethead();
							while(temp2->next != NULL){
								if((uname == temp2->c_name) && (pass == temp2->password)){
									temp2->t_pur = temp2->t_pur + temp->price;
								}
								temp2 = temp2->next;
							}
							ofstream writefile;
							writefile.open("buyers12.txt", ios::in);
							if(!writefile){
								cout<<"File could not be opened."<<endl;
								exit(1);
							}
							else{
								cxNode* temp2 = customer.gethead();
								while(temp2->next!=NULL){
									writefile << temp2->c_name << " \t" << temp2->password << " \t" << temp2->contact_num <<"\t"<<temp2->t_pur<<endl;
									temp2 = temp2->next;
								}
							}
							writefile.close();
							
						}
						
						}
						else{
							cout<<"ENTERED MODEL IS NOT AVAIALBALE!"<<endl;
							cout<<"PLEASE ENTER AGAIN"<<endl;
							goto ChooseAfterSort;
						}
						}
						
						// IPHONE SEARCHING
						else if(option==2){
						if(iphone.searchbst(root2, buy)){     
						flag=1;
						node* temp = iphone.searchbst(root2,buy);
						//
						system("CLS");
						//
						cout<<endl<<"\t\t***YOUR PRODUCT***"<<endl<<endl;
						cout<<temp->name<<"\t"<<temp->price<<"\t"<<temp->year<<endl;
						cout<<endl<<"\t\t"<<"THANKS FOR SHOPPING"<<endl<<endl<<endl;
						if(userc==1){
							customer.insert(uname, cont, temp->price ,pass);    
							
							ofstream writefile;
							writefile.open("buyers12.txt", ios::in);
							if(!writefile){
								cout<<"File could not be opened."<<endl;
								exit(1);
							}
							else{
								cxNode* temp2 = customer.gethead();
								while(temp2->next!=NULL){
									writefile << temp2->c_name << " \t" << temp2->password << " \t" << temp2->contact_num <<"\t"<<temp2->t_pur<<endl;
									temp2 = temp2->next;
								}
								writefile << temp2->c_name << " \t" << temp2->password << " \t" << temp2->contact_num <<"\t"<<temp2->t_pur<<endl;
							}
							writefile.close();		
									
						}
						
						if(userc==2){
							cxNode* temp2 = customer.gethead();
							while(temp2->next != NULL){
								if((uname == temp2->c_name) && (pass == temp2->password)){
									temp2->t_pur = temp2->t_pur + temp->price;
								}
								temp2 = temp2->next;
							}
							ofstream writefile;
							writefile.open("buyers12.txt", ios::in);
							if(!writefile){
								cout<<"File could not be opened."<<endl;
								exit(1);
							}
							else{
								cxNode* temp2 = customer.gethead();
								while(temp2->next!=NULL){
									writefile << temp2->c_name << " \t" << temp2->password << " \t" << temp2->contact_num <<"\t"<<temp2->t_pur<<endl;
									temp2 = temp2->next;
								}
							}
							writefile.close();
							
						}
						
						}
						else{
							cout<<"ENTERED MODEL IS NOT AVAIALBALE!"<<endl;
							cout<<"PLEASE ENTER AGAIN"<<endl;
							goto ChooseAfterSort;
						}
						}
							
							
						// HUAWEI SEARCHING
						else if(option==3){
						if(huawei.searchbst(root3, buy)){     
						flag=1;
						node* temp = huawei.searchbst(root3,buy);
						//
						system("CLS");
						//
						cout<<endl<<"\t\t***YOUR PRODUCT***"<<endl<<endl;
						cout<<temp->name<<"\t"<<temp->price<<"\t"<<temp->year<<endl;
						cout<<endl<<"\t\t"<<"THANKS FOR SHOPPING"<<endl<<endl<<endl;
						if(userc==1){
							customer.insert(uname, cont, temp->price ,pass);    
							
							ofstream writefile;
							writefile.open("buyers12.txt", ios::in);
							if(!writefile){
								cout<<"File could not be opened."<<endl;
								exit(1);
							}
							else{
								cxNode* temp2 = customer.gethead();
								while(temp2->next!=NULL){
									writefile << temp2->c_name << " \t" << temp2->password << " \t" << temp2->contact_num <<"\t"<<temp2->t_pur<<endl;
									temp2 = temp2->next;
								}
								writefile << temp2->c_name << " \t" << temp2->password << " \t" << temp2->contact_num <<"\t"<<temp2->t_pur<<endl;
							}
							writefile.close();		
									
						}
						
						if(userc==2){
							cxNode* temp2 = customer.gethead();
							while(temp2->next != NULL){
								if((uname == temp2->c_name) && (pass == temp2->password)){
									temp2->t_pur = temp2->t_pur + temp->price;
								}
								temp2 = temp2->next;
							}
							ofstream writefile;
							writefile.open("buyers12.txt", ios::in);
							if(!writefile){
								cout<<"File could not be opened."<<endl;
								exit(1);
							}
							else{
								cxNode* temp2 = customer.gethead();
								while(temp2->next!=NULL){
									writefile << temp2->c_name << " \t" << temp2->password << " \t" << temp2->contact_num <<"\t"<<temp2->t_pur<<endl;
									temp2 = temp2->next;
								}
							}
							writefile.close();
							
						}
						
						}
						else{
							cout<<"ENTERED MODEL IS NOT AVAIALBALE!"<<endl;
							cout<<"PLEASE ENTER AGAIN"<<endl;
							goto ChooseAfterSort;
						}
						}
						
						else if(option==4){
						if(oneplus.searchbst(root4, buy)){     
						flag=1; 
						node* temp = oneplus.searchbst(root4,buy);
						//
						system("CLS");
						//
						cout<<endl<<"\t\t***YOUR PRODUCT***"<<endl<<endl;
						cout<<temp->name<<"\t"<<temp->price<<"\t"<<temp->year<<endl;
						cout<<endl<<"\t\t"<<"THANKS FOR SHOPPING"<<endl<<endl<<endl;
						if(userc==1){
							customer.insert(uname, cont, temp->price ,pass);    
							
							ofstream writefile;
							writefile.open("buyers12.txt", ios::in);
							if(!writefile){
								cout<<"File could not be opened."<<endl;
								exit(1);
							}
							else{
								cxNode* temp2 = customer.gethead();
								while(temp2->next!=NULL){
									writefile << temp2->c_name << " \t" << temp2->password << " \t" << temp2->contact_num <<"\t"<<temp2->t_pur<<endl;
									temp2 = temp2->next;
								}
								writefile << temp2->c_name << " \t" << temp2->password << " \t" << temp2->contact_num <<"\t"<<temp2->t_pur<<endl;
							}
							writefile.close();		
									
						}
						
						if(userc==2){
							cxNode* temp2 = customer.gethead();
							while(temp2->next != NULL){
								if((uname == temp2->c_name) && (pass == temp2->password)){
									temp2->t_pur = temp2->t_pur + temp->price;
								}
								temp2 = temp2->next;
							}
							ofstream writefile;
							writefile.open("buyers12.txt", ios::in);
							if(!writefile){
								cout<<"File could not be opened."<<endl;
								exit(1);
							}
							else{
								cxNode* temp2 = customer.gethead();
								while(temp2->next!=NULL){
									writefile << temp2->c_name << " \t" << temp2->password << " \t" << temp2->contact_num <<"\t"<<temp2->t_pur<<endl;
									temp2 = temp2->next;
								}
							}
							writefile.close();
							
						}
						
						}
						else{
							cout<<"ENTERED MODEL IS NOT AVAIALBALE!"<<endl;
							cout<<"PLEASE ENTER AGAIN"<<endl;
							goto ChooseAfterSort;
						}
						}
						
						
					// NOKIA SEARCHING	
						else if(option==5){
						if(nokia.searchbst(root5, buy)){     
						flag=1; 
						node* temp = nokia.searchbst(root5,buy);
						//
						system("CLS");
						//
						cout<<endl<<"\t\t***YOUR PRODUCT***"<<endl<<endl;
						cout<<temp->name<<"\t"<<temp->price<<"\t"<<temp->year<<endl;
						cout<<endl<<"\t\t"<<"THANKS FOR SHOPPING"<<endl<<endl<<endl;
						if(userc==1){
							customer.insert(uname, cont, temp->price ,pass);    
							
							ofstream writefile;
							writefile.open("buyers12.txt", ios::in);
							if(!writefile){
								cout<<"File could not be opened."<<endl;
								exit(1);
							}
							else{
								cxNode* temp2 = customer.gethead();
								while(temp2->next!=NULL){
									writefile << temp2->c_name << " \t" << temp2->password << " \t" << temp2->contact_num <<"\t"<<temp2->t_pur<<endl;
									temp2 = temp2->next;
								}
								writefile << temp2->c_name << " \t" << temp2->password << " \t" << temp2->contact_num <<"\t"<<temp2->t_pur<<endl;
							}
							writefile.close();		
									
						}
						
						if(userc==2){
							cxNode* temp2 = customer.gethead();
							while(temp2->next != NULL){
								if((uname == temp2->c_name) && (pass == temp2->password)){
									temp2->t_pur = temp2->t_pur + temp->price;
								}
								temp2 = temp2->next;
							}
							ofstream writefile;
							writefile.open("buyers12.txt", ios::in);
							if(!writefile){
								cout<<"File could not be opened."<<endl;
								exit(1);
							}
							else{
								cxNode* temp2 = customer.gethead();
								while(temp2->next!=NULL){
									writefile << temp2->c_name << " \t" << temp2->password << " \t" << temp2->contact_num <<"\t"<<temp2->t_pur<<endl;
									temp2 = temp2->next;
								}
							}
							writefile.close();
							
						}
						
						}
						else{
							cout<<"ENTERED MODEL IS NOT AVAIALBALE!"<<endl;
							cout<<"PLEASE ENTER AGAIN"<<endl;
							goto ChooseAfterSort;
						}
						}
						
					// REDMI SEARCHING
						else if(option==6){
						if(redmi.searchbst(root6, buy)){     
						flag=1; 
						node* temp = redmi.searchbst(root6,buy);
						//
						system("CLS");
						//
						cout<<endl<<"\t\t***YOUR PRODUCT***"<<endl<<endl;
						cout<<temp->name<<"\t"<<temp->price<<"\t"<<temp->year<<endl;
						cout<<endl<<"\t\t"<<"THANKS FOR SHOPPING"<<endl<<endl<<endl;
						if(userc==1){
							customer.insert(uname, cont, temp->price ,pass);    
							
							ofstream writefile;
							writefile.open("buyers12.txt", ios::in);
							if(!writefile){
								cout<<"File could not be opened."<<endl;
								exit(1);
							}
							else{
								cxNode* temp2 = customer.gethead();
								while(temp2->next!=NULL){
									writefile << temp2->c_name << " \t" << temp2->password << " \t" << temp2->contact_num <<"\t"<<temp2->t_pur<<endl;
									temp2 = temp2->next;
								}
								writefile << temp2->c_name << " \t" << temp2->password << " \t" << temp2->contact_num <<"\t"<<temp2->t_pur<<endl;
							}
							writefile.close();		
									
						}
						
						if(userc==2){
							cxNode* temp2 = customer.gethead();
							while(temp2->next != NULL){
								if((uname == temp2->c_name) && (pass == temp2->password)){
									temp2->t_pur = temp2->t_pur + temp->price;
								}
								temp2 = temp2->next;
							}
							ofstream writefile;
							writefile.open("buyers12.txt", ios::in);
							if(!writefile){
								cout<<"File could not be opened."<<endl;
								exit(1);
							}
							else{
								cxNode* temp2 = customer.gethead();
								while(temp2->next!=NULL){
									writefile << temp2->c_name << " \t" << temp2->password << " \t" << temp2->contact_num <<"\t"<<temp2->t_pur<<endl;
									temp2 = temp2->next;
								}
							}
							writefile.close();
							
						}
						
						}
						else{
							cout<<"ENTERED MODEL IS NOT AVAIALBALE!"<<endl;
							cout<<"PLEASE ENTER AGAIN"<<endl;
							goto ChooseAfterSort;
						}
						}
						
					}while(flag==0);
					
				}
			}
			
		}
		}while(o=='n');
	}
	
	return 0;
}




