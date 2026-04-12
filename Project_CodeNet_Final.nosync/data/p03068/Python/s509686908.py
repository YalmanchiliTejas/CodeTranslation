user_input=[]
for i in range(3):
    user_input.append(input())
N=int(user_input[0])
S=user_input[1]
K=int(user_input[2])-1

S_list=[]
for i in S:
    S_list.append(i)

obj=S_list[K]
for i in range(N):
    if S_list[i] != obj:
        S_list[i]='*'
S_after=''.join(S_list)
print(S_after)