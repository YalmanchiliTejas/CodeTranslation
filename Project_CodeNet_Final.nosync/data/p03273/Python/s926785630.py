h,w=map(int,input().split())
#a=[[j for j in input()] for i in range(h)]

lis=[]
for i in range(h):
#     a=list(map(str,input().split()))
    a = list(input())
    if '#' in a:
        lis.append(a)
lis2=list(zip(*lis))
lis_ans=[]
for i in range(w):
    if '#' in lis2[i]:
        lis_ans.append(lis2[i])
lis_ans = list(zip(*lis_ans))
# print(list(zip(*lis_ans)))
# print(lis_ans)
for i in range(len(lis_ans)):
    print(''.join(lis_ans[i]))