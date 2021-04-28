/*
 * Polynomials sum using Link List
 * Developer: Muhammad Sikander Iqbal
 * Contact: taimoorahamed95959@gmail.com , www.fiverr.com/phoenixhub947
 * CopyRight @ Phoenix Hub You are not allowed to use any section of this program. This code is just for learning purpose.
 * Version: 1.0.1
 * Updated on 29-04-2021 @ 04:15 AM PKT
 */

#include<stdio.h>
#include<stdlib.h>
struct Node
{
 int coeff;
 int pow;
 struct Node* next;
};
void readPolynomial(struct Node** poly)
{
 int coeff, exp, cont;
 struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
 *poly = temp;
 do{
 printf("\n Coeffecient: ");
 scanf("%d", &coeff);
 printf("\n Exponent: ");
 scanf("%d", &exp);
 temp->coeff = coeff;
 temp->pow = exp;
 temp-> next = NULL;
 printf("\nHave more terms? 1 for y and 0 for no: ");
 scanf("%d", &cont);
 if(cont)
 {
 temp->next = (struct Node*)malloc(sizeof(struct Node));
 temp = temp->next;
 temp->next = NULL;
 }
 }while(cont);
}
void displayPolynomial(struct Node* poly)
{
 while(poly != NULL)
 {
 printf("%dX^%d ", poly->coeff, poly->pow);
 poly = poly->next;
 if(poly != NULL)
 printf("+ ");
 }
}
void addPolynomials(struct Node** result, struct Node* first, struct Node*
second)
{
 struct Node* temp = (struct Node*)malloc(sizeof(struct Node)), *del;
 temp->next = NULL;
 *result = temp;
 while(first && second)
 {
 if(first->pow > second->pow)
 {
 temp->coeff = first->coeff;
 temp->pow = first->pow;
 first = first->next;
 }
 else if(first->pow < second->pow)
 {
 temp->coeff = second->coeff;
 temp->pow = second->pow;
 second = second->next;
 }
 else
 {
 temp->coeff = first->coeff + second->coeff;
 temp->pow = first->pow;
 first = first->next;
 second = second->next;
 }
 del = temp;
 temp->next = (struct Node*)malloc(sizeof(struct Node));
 temp = temp->next;
 temp->next = NULL;
 }
 while(first || second)
 {
 if(first)
 {
 temp->coeff = first->coeff;
 temp->pow = first->pow;
 first = first->next;
 }
 else if(second)
 {
 temp->coeff = second->coeff;
 temp->pow = second->pow;
 second = second->next;
 }
 del = temp;
 temp->next = (struct Node*)malloc(sizeof(struct Node));
 temp = temp->next;
 temp->next = NULL;
 }
 del->next = NULL;
 free(temp->next);
}
int main()
{
 struct Node* first = NULL;
 struct Node* second = NULL;
 struct Node* result = NULL;
 printf("\nEnter the corresponding data:-\n");
 printf("\nFirst polynomial:\n");
 readPolynomial(&first);
 printf("\nFirst polynomial:");
 displayPolynomial(first);
 printf("\n\nSecond polynomial:\n");
 readPolynomial(&second);
 printf("\nSecond polynomial:");
 displayPolynomial(second);
 printf("\n\nSum of polynomials:\n\n");
 displayPolynomial(first);
 printf("\n");
 displayPolynomial(second);
 printf("\n");
 printf("--------------------");
 printf("\n");
 addPolynomials(&result, first, second);
 displayPolynomial(result);
 return 0;
}
