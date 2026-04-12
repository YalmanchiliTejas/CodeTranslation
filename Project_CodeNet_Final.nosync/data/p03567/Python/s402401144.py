#n=int(input())
#A=list(map(int,input().split()))
#b=list(map(int,input().split()))
s=list(input())
n=len(s)
for i in range(n-1):
        tmp="".join(s[i:i+2])
        if tmp=="AC":
                print("Yes")
                exit()
print("No")