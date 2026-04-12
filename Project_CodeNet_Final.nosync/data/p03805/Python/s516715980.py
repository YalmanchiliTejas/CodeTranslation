import itertools

n, m=map(int, input().split())
branch=[]
for i in range(m):
    a, b=map(int, input().split())
    branch.append((a, b))
seq=[]
for i in range(2, n+1):
    seq.append(i)
ans=0
permutation=list(itertools.permutations(seq))
for i in range(len(permutation)):
    number_list=list(map(int, permutation[i]))
    start=1
    flag=1
    for j in range(n-1):
        if not ((start, number_list[j]) in branch or (number_list[j], start) in branch):
            flag=0
            break
        start=number_list[j]
    if flag:
        ans=ans+1
print(ans)
