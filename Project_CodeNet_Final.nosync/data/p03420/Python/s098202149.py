# cook your dish here
n,k = map(int,input().split())
ass = 0

for i in range(k+1,n+1):
    jkl = ass
    ass += (i-1)-k+1
    w = (n-(i-1))//i
    if w >= 1:
        ass += ((i-1)-k+1)*w
    r = n-(w+1)*i
    if r >= k:
        ass += r-k+1
    #print(i,ass-jkl)
if k ==0:
    print(n**2)
else:
    print(ass)