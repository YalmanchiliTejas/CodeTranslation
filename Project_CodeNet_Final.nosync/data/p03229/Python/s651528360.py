
N = int(input())
Alist=[]
# Blist=[]
for i in range(0,N):
    Alist.append(int(input()))

Alist.sort()
# print(Alist)

back=N-1

numA=Alist[0]
numB=Alist[back]
ans = abs(numB-numA)
back-=1
# print(ans)

for i in range(1,int(N/2)):
    if i%2 == 0:
        ans+=abs(numA-Alist[i])
        numA=Alist[i]
        ans+=abs(numB-Alist[back])
        numB=Alist[back]
        # print(ans)
    else:
        ans+=abs(numB-Alist[i])
        numB=Alist[i]
        ans+=abs(numA-Alist[back])
        numA=Alist[back]
    back-=1
    # print(ans)

# print("l-")

if N%2 == 1:
    k=int(N/2)
    # print(k)
    if abs(numA-Alist[k]) > abs(numB-Alist[k]):
        ans+=abs(numA-Alist[k])
        numA=Alist[k]
    else:
        ans+=abs(numB-Alist[k])
        numB=Alist[k]
    # print(ans)

# print("a-")
print(ans)
