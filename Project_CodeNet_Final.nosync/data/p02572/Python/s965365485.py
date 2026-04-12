n=int(input())
v=pow(10,9)+7
arr=list(map(int,input().split()))
s=sum(arr)
it=0
for item in arr:
    it+=item**2
print (((s**2-it)//2)%v)