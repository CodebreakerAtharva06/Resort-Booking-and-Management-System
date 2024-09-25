#include<iostream>
using namespace std;

class tbtnode{
	bool rbit;
	tbtnode *left;
	char data;
	tbtnode *right;
	bool lbit;
	public:
	friend class tbt;
	tbtnode(){
		lbit=1;
		rbit=1;
	}
	
};

class tbt{
	private:
	tbtnode *head;
	public:
	void create();
	void inorder();
	void preorder();
	tbtnode *inordersucc(tbtnode *);
	tbt(){
		head = new tbtnode;
		head->rbit =0;
		head->left = head;
		head->right = head;
	}
};

void tbt::create(){
	tbtnode *root,*temp,*curr;
	root = new tbtnode;
	cout<<"\nenter root data: ";
	cin>>root->data;
	head->lbit =0;
	root->left = head;
	root->right = head;
	head->left = root;
	int flag;
	char c1;
	int c2;
	
	do{
		flag =0;
		temp = root;
		curr = new tbtnode;
		cout<<"\nenter data for node: ";
		cin>>curr->data;
		while (flag ==0){
			cout<<"\nenter node to the left or right of "<<temp->data<<" : ";
			cin>>c1;
			if (c1 == 'l'){
				if (temp->lbit == 1){
					curr->left = temp->left;
					curr->right = temp;
					temp->left = curr;
					temp->lbit = 0;
					flag = 1;
				}
				else temp = temp->left;
			}
			else {
				if (temp->rbit == 1){
					curr->left = temp;
					curr->right = temp->right;
					temp->right = curr;
					temp->rbit = 0;
					flag = 1;
				}
				else temp = temp->right;
			}
		}
		cout<<"\ndo you want to add another node? press 1 for yes \nchoice: ";
		cin>>c2;
	}while(c2==1);
}

tbtnode *tbt::inordersucc(tbtnode *temp){
	tbtnode *x;
	x = temp->right;
	if(temp->rbit ==0){
		while(x->lbit == 0){
			x= x->left;
		}
	}
	return x;
}

void tbt::inorder(){
	cout<<"\ninorder traversal: ";
	tbtnode *temp;
	temp=head;
	while(1){
		temp = inordersucc(temp);
		if (temp == head) break;
		cout<<temp->data<<"\t";
	}
	cout<<endl;
}

void tbt::preorder(){
	cout<<"\npreorder traversal is: ";
	tbtnode *temp;
	temp= head->left;
	while (temp != head){
		cout<<temp->data<<"\t";
		while(temp->lbit != 1){
			temp = temp->left;
			cout<<temp->data<<"\t";
		}
		
		while(temp->rbit ==1){
			temp = temp->right;
		}
		temp = temp->right;
	}
	cout<<endl;
}

/*
FUNCTION TO PRINT LEAF NODES

void tbt::leafnodes(){
	cout<<"\npreorder traversal is: ";
	tbtnode *temp;
	temp= head->left;
	while (temp != head){
		if (temp->lbit ==1 and temp->rbit ==1) cout<<temp->data<<"\t";
		while(temp->lbit != 1){
			temp = temp->left;
			if (temp->lbit ==1 and temp->rbit ==1) cout<<temp->data<<"\t";
		}
		
		while(temp->rbit ==1){
			temp = temp->right;
		}
		temp = temp->right;
	}
	cout<<endl;
}*/

int main(){
	cout<<"jello world\n";
	tbt tree;
	tree.create();
	tree.inorder();
	tree.preorder();
	return 0;
}

/*
OUTPUT

saanvi@her-techplay:~/code/cpp$ g++ ads4.cpp
saanvi@her-techplay:~/code/cpp$ ./a.out
jello world

enter root data: a

enter data for node: b

enter node to the left or right of a : l

do you want to add another node? press 1 for yes 
choice: 1

enter data for node: c

enter node to the left or right of a : r

do you want to add another node? press 1 for yes 
choice: 1

enter data for node: d

enter node to the left or right of a : l

enter node to the left or right of b : l

do you want to add another node? press 1 for yes 
choice: 1

enter data for node: e

enter node to the left or right of a : l

enter node to the left or right of b : r

do you want to add another node? press 1 for yes 
choice: 1

enter data for node: f

enter node to the left or right of a : r

enter node to the left or right of c : l

do you want to add another node? press 1 for yes 
choice: 1

enter data for node: g

enter node to the left or right of a : r

enter node to the left or right of c : r

do you want to add another node? press 1 for yes 
choice: 1

enter data for node: h

enter node to the left or right of a : l

enter node to the left or right of b : l
enter node to the left or right of d : l 

do you want to add another node? press 1 for yes 
choice: 1

enter data for node: i

enter node to the left or right of a : l

enter node to the left or right of b : l

enter node to the left or right of d : r

do you want to add another node? press 1 for yes 
choice: 0

inorder traversal: h	d	i	b	e	a	f	c	g	

preorder traversal is: a	b	d	h	i	e	c	f	g	


*/


