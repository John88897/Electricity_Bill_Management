#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_CUSTOMER 100
#define COST_PER_UNIT 500 //in riels

typedef struct{
    int customerID;
    char name[MAX_CUSTOMER];
    int preReading;
    int currReading;
    float billAmount;
    int paidStatus; // 0 for not paid, 1 for paid
}Customer;


//set maximum num of customer to 100 meaning 100 of struct called Customer
Customer customer[MAX_CUSTOMER];
int customerCount=0;
//calcutlate to bill
int calculatebill(int preReading,int currReading){
    int value=currReading-preReading;
    return value*COST_PER_UNIT;
}
//add customer
void addCustomer(){
    if(customerCount>=MAX_CUSTOMER){
        printf("customer limit reached");
        return ;
    }
    Customer c;
    //get id
    printf("enter customer id: ");
    scanf("%d", &c.customerID);
    //get name
    printf("enter customer name: ");
    scanf("%s",c.name);
    //get address
    
    //get pre reading
    printf("enter previous reading: ");
    scanf("%d",&c.preReading);
    //get current reading
    printf("enter current reading: ");
    scanf("%d", &c.currReading);
    //calculate the bill
    c.billAmount=calculatebill(c.preReading,c.currReading);
    //set the currently adding c to custommer which has the index of customerCount +1
    customer[customerCount++]=c;
    c.paidStatus = 0; // Initialize as not paid
    
    printf("adding successfully");  
}
void displayAllBill(){
    if(customerCount==0){
        printf("No customer to display!");
        return;
    }
    for(int i=0;i<customerCount;i++){
        printf("-------customer %d-------",i+1);
        printf("\nCustomer ID: %d\n",customer[i].customerID);
        printf("\nCustomer Name: %s \n",customer[i].name);
        printf("\ncustomer Prevous meter: %d\n",customer[i].preReading);
        printf("\nCutomer current mter: %d\n",customer[i].currReading);
        printf("\nCustomer bill: %.2f Riels\n",customer[i].billAmount);
        printf("Payment Status: %s\n", customer[i].paidStatus ? "Paid" : "Not Paid");
    }
}
//search customer by their ID
void searchCustomer(){
    if(customerCount==0){
        printf("No customer to search");
        return;
    }
    int searchID;
    int found=0;
    printf("enter customer id to seaarch: ");
    scanf("%d", &searchID);
    for(int i=0;i<customerCount;i++){
        if(customer->customerID==searchID){
          printf("-------customer %d-------",i+1);
        printf("\nCustomer ID: %d\n",customer[i].customerID);
        printf("\nCustomer Name: %s \n",customer[i].name);
        printf("\ncustomer Prevous meter: %d\n",customer[i].preReading);
        printf("\nCutomer current mter: %d\n",customer[i].currReading);
        printf("\nCustomer bill: %.2f Riels\n",customer[i].billAmount);
        printf("Payment Status: %s\n", customer[i].paidStatus ? "Paid" : "Not Paid");
        found=1; 
        break; 
        }
    }
    if(found==0){
        printf("No customer with this id");
    }
}
void setCustomertoPaid(){
    if(customerCount==0){
        printf("no customer id to mark as paid");
        return;
    }
    int searchID;
    printf("enter customer id to set as paid: ");
    scanf("%d",&searchID);
    int found=0;
    for(int i=0;i<customerCount;i++){
        if(customer->customerID==searchID){
            customer->paidStatus=1;
            printf("set successfully");
            found=1;
            break;
        }
    }
    if(found==0){
        printf("no customer with this id");
    }
}
int main(){
   int choice;
   do{
    printf("\nelectricity bill management system: \n");
    printf("\n1: ADD CUSTOMER \n");
    printf("\n2: DISPLAY ALL BILL\n");
    printf("\n3: search customer\n");
    printf("\n4: MARK CUSTOMER AS PAID\n"); 
    printf("5: EXIT\n");
    scanf("%d",&choice);
    switch (choice){
        case 1:
        addCustomer();
        break;
        case 2:
        displayAllBill();
        break;
        case 3:
        searchCustomer();
        break;
        case 4:
        setCustomertoPaid();
        break;
        case 5:
        printf("exiting\n");
        break;
        default:
        printf("invalid choice try again\n");
    }
   }while (choice!=3);
   
   
    
    return 0;

}
