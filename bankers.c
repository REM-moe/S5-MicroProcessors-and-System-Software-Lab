#include<stdio.h>
int main() {
int p, r, allocation[20][20], max[20][20], s[20], need[20]
[20], available[20], work[20], finish[20], i, j, l, t, flag, counter;
printf("Enter the number of processes:");
scanf("%d", & p);
printf("Enter the number of resources:");
scanf("%d", & r);
printf("Enter the Allocaion Matrix:\n");
for (i = 0; i < p; i++) {
for (j = 0; j < r; j++) {
scanf("%d", & allocation[i][j]);
}
}
printf("Allocation Matrix:\n");
for (i = 0; i < p; i++) {
for (j = 0; j < r; j++) {
printf("%d\t", allocation[i][j]);
}
printf("\n");
}
printf("Enter the Max Matrix:\n");
for (i = 0; i < p; i++) {
for (j = 0; j < r; j++) {
scanf("%d", & max[i][j]);
}
}
printf("Max Matrix:\n");
for (i = 0; i < p; i++) {
for (j = 0; j < r; j++) {
printf("%d\t", max[i][j]);
}
printf("\n");
}
printf("Enter available:");
for (i = 0; i < r; i++) {
scanf("%d", & available[i]);
}
printf("Need Matrix:\n");
for (i = 0; i < p; i++) {

for (j = 0; j < r; j++) {
need[i][j] = max[i][j] - allocation[i][j];
printf("%d\t", need[i][j]);
}
printf("\n");
}
for (i = 0; i < r; i++) {
work[i] = available[i];
}
for (i = 0; i < p; i++) {
finish[i] = 0;
}
counter = p;
l = 0;
while (counter != 0) {
for (i = 0; i < p; i++) {
if (finish[i] == 0) {
t = 0;
for (j = 0; j < r; j++) {
if (need[i][j] > work[j]) {
t = 1;
break;
}
}
if (t == 0) {
counter--;
s[l] = i;
l++;
finish[i] = 1;
for (int j = 0; j < r; j++) {
work[j] = work[j] + allocation[i][j];
}}}}}
flag = 0;
for (i = 0; i < p; i++) {
if (finish[i] == 0)
{
flag = i;
printf("System is not safe!\n");
break;
}
}
if (flag == 0) {
printf("Safe state!\n");
printf("Safe Sequence:\n");

for (i = 0; i < p; i++) {
printf("p%d\t", s[i]);
}
printf("\n");
}
return 0;
}
