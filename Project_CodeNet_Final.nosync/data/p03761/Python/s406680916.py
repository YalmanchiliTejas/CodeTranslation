from collections import Counter

n=int(input())
ans=''
counter={}
for i in range(1,n+1):
    if i==1:
        s=input()
        counter=Counter()
        counter=Counter(s)
    else:
        s=input()
        counter=Counter(s)&counter

for c in [chr(i) for i in range(ord('a'), ord('z')+1)]:
    ans=ans+c*counter[c]
print(ans)