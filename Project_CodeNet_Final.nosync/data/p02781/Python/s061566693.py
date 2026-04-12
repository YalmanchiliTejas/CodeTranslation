s=input()+"9";n=len(s);X=[(0,0)]*4;
while n:
 n-=1;k=4
 while k:k-=1;a=int(s[n]);X[k]=(X[k][0]+9*X[k-1][0],X[k][0]+(a-1)*X[k-1][0]+X[k-1][1]if a else X[k][1])if k else(1,1)
print(X[int(input())][1])