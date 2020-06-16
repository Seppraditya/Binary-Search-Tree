#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
typedef struct Node

//Septian Aditya P
// ig:seppraditya

{
    int data;
    Node *kiri;
    Node *kanan;
};

Node *tree = NULL;


void insert_bst (Node **root, int Newdata){
     
    if ((*root)==NULL){
            
        Node *baru;  
        baru = new Node;
     
        baru->data=Newdata;
        baru->kiri=NULL;
        baru->kanan=NULL;
        (*root) = baru;
        (*root) -> kiri = NULL;
        (*root) -> kanan = NULL;
     
        printf("Data Bertambah!");
       }

    else if (Newdata<(*root)->data)
              insert_bst(&(*root)->kiri,Newdata);

    else if (Newdata>(*root)->data)
        insert_bst(&(*root)->kanan,Newdata);

    else if (Newdata==(*root)->data)
        printf("Data Sudah ada!");
}


void preOrder(Node *root)
{
    if(root!=NULL){
        if(root->data!=NULL){
            printf("%d ",root->data);
        }
        preOrder(root->kiri);
        preOrder(root->kanan);
    }
}


void inOrder(Node *root)
{
       if(root!=NULL) {
           inOrder(root->kiri);
           if(root->data!=NULL){
               printf("%d ",root->data);
           }
           inOrder(root->kanan);
        }
}


void postOrder(Node *root){
       if(root!=NULL) {
         postOrder(root->kiri);
         postOrder(root->kanan);
         if(root->data!=NULL) {
            printf("%d ",root->data);
         }
       }
}


void search(Node **root, int cari){
    if((*root) == NULL) {
        printf("Tidak ditemukan!");
    }

    else if(cari < (*root)->data)
        search(&(*root)->kiri,cari);

    else if(cari > (*root)->data)
        search(&(*root)->kanan,cari);
  
    else if(cari == (*root)->data)
        printf("Ditemukan!");
}


int count(Node *root){
       if(root==NULL)
              return 0;
       else
              return count(root->kiri)+ count(root->kanan)+1;
}


int height(Node *root){
       if(root == NULL)
              return -1;
       else{
                int u = height(root->kiri);
            	int v = height(root->kanan);
        if(u > v)
          return u + 1;
        else
          return v + 1;
       }
}



void hapus(Node **root, int del){
       Node *curr;
       Node *parent;
       curr = (*root);

       bool flag = false;
       while(curr != NULL){
              if(curr->data == del)
              {
                     flag = true;
                      break;
              }
              else
              {
                  parent = curr;
                  if(del>curr->data)
                     curr = curr->kanan;
                  else
                     curr = curr->kiri;
              }
       }

    if(!flag){
        cout<<"Data tidak ditemukan. Penghapusan tidak dilakukan."<<endl;
        return;
    }


       if(height(tree) == 0){
              if( curr->kiri== NULL && curr->kanan == NULL) {
                     (*root) = NULL;
                    
                     return;
              }
       }

       else if(height(tree) > 0) {

              if( curr->kiri== NULL && curr->kanan == NULL){
           
                     if(parent->kiri == curr) {
                       
                           parent->kiri = NULL;
                           delete curr;
                     }
                     else  {
                           parent->kanan = NULL;
                           delete curr;
                     }

                     return;
              }


              if((curr->kiri == NULL && curr->kanan != NULL)|| (curr->kiri != NULL && curr->kanan == NULL)){
                  
                     if(curr->kiri == NULL && curr->kanan != NULL) {
                         
                           if(parent->kiri == curr){
                              parent->kiri = curr->kanan;
                              delete curr;
                        		 }
                         else {
                       
                              parent->kanan = curr->kanan; 
                              delete curr;
                         }
                     }
                     
                  else  {
                        
                           if(parent->kiri == curr)
                           {
                                  parent->kiri = curr->kiri; 
                                  delete curr;
                           }
                           else 
                           {
                               parent->kanan = curr->kiri; 
                               delete curr;
                            }
                   }
                   return;
              }


            
              if (curr->kiri != NULL && curr->kanan != NULL){
                 
                     Node* bantu;
                     bantu = curr->kanan;

                  
                     if((bantu->kiri == NULL) && (bantu->kanan == NULL)) {
                           curr = bantu;
                           delete bantu;
                           curr->kanan = NULL;
                     }
                     else {
                  
                           if((curr->kanan)->kiri != NULL) {
                                
                                  Node* bantu2;
                                  Node* bantu3; 
                                  bantu3 = curr->kanan;         
                                  bantu2 = (curr->kanan)->kiri; 

                            
                                  while(bantu2->kiri != NULL) {
                                         bantu3 = bantu2;
                                         bantu2 = bantu2->kiri;
                                  }
   
                                  curr->data = bantu2->data;
                                  delete bantu2;
                                  bantu3->kiri = NULL;
                        }
                        else {
                              Node* tmp;
                              tmp = curr->kanan;
                             
                              curr->data = tmp->data;
                              curr->kanan = tmp->kanan;
                              delete tmp;
                        }

                     }
                     return;
              }
       }
}


int main()
{
  
    int pilihan;
    int del,cari;
    while (true)
    {
        system("cls"); 
        char data;
        printf("\n============================");
        printf("\nBinary Search Tree");
        printf("\n============================\n");
        printf("1. Masukan Data\n");
        printf("2. Tampilkan Pre-Order,InOrder, dan PostOrder\n");
        printf("3. Delete Data\n");
        printf("4. Reset Data\n");
        printf("5. Cari Data\n");
        printf("6. Tampilkan data terbesar & terkecil\n");
        printf("0. Keluar\n");
        printf("Pilihan Anda : ");
        scanf("%i",&pilihan);
        fflush(stdin);
        switch(pilihan)
        {
            
            case 1:
                     
                     printf("\n\nMasukkan data: ");
                     scanf("%d", &data);   
                     insert_bst(&tree,data);
                     _getch();
                      break;
                     
            case 2 :
            		if(tree!=NULL){
            			printf("\nPreOrder  : ");
                        preOrder(tree); 
                        printf("\nInOrder   : ");
                        inOrder(tree); 
                        printf("\nPostOrder : ");
                        postOrder(tree);
					}	    	
                    else {
                    	 printf("\nData belum ada!");
					}
                    _getch();
                     break;
                     
            case 3 :
            		if(tree!=NULL){
            			printf("\n\nMasukkan data yang ingin dihapus: ");
                        scanf("%d", &del);
                        hapus(&tree, del);
                        printf("simpul %d telah di hapus", del);
					}else {
						printf("\nData belum ada!");
					}
					_getch();
                     break;
					
            case 4 :
				tree = NULL;
				printf("\nTree telah di reset, data sekarang kosong!");
				
				 _getch();
                     break;
						
            case 5 :
				
				if(tree!=NULL){
					printf("\n\nMasukkan data yang ingin dicari : ");
                    scanf("%d", &cari);
                    search(&tree, cari);
				} else {
					printf("\nData belum ada!");
				}   
				  
				_getch();
                     break;
                     
            case 6 :
            	if(tree!=NULL){
            		printf("\n\dari beberapa data ini");
            		printf("\n=======================\n");
            		preOrder(tree);
            		printf("\n=======================");
            		printf("\nUrutan dari data terkecil : "); 
            		inOrder(tree);
            		printf("\nUrutan dari data terbesar : ");
            		postOrder(tree);
            			
            		
				} else{
					printf("\nData belum ada!");
				}
				
				_getch();
                break;
						
             
              }
       }
}
