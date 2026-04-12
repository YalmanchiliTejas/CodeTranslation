n=int(input())
s=list(map(int,input().split()))
cnt=0
tmp=s[0]

for i in range(n):
            if s[i]>=tmp:
                        cnt+=1
                        tmp=s[i]
print(cnt)

                      
