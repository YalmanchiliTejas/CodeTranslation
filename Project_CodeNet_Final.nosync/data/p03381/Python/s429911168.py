n=int(input())

a=list(map(int,input().split()))

a_s=sorted(a)

bf=a_s[n//2-1]
bl=a_s[n//2]

for ele in a:
    if(ele>=bl):
        print(bf)
    else:
        print(bl)