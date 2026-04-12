s=input()+"9";n=len(s);X=[0]*4;Y=[0]*4;
while n:
 n-=1;k=4
 while k:k-=1;a=int(s[n]);Y[k],X[k]=(X[k]+(a-1)*X[k-1]+Y[k-1]if a else Y[k],X[k]+9*X[k-1])if k else (1,1)
print(Y[int(input())])