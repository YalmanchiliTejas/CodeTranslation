N=int(input())
H_lst=list(map(int,input().split()))
S = H_lst[0]
count = 1
for i in range(N-1):
    if S <= H_lst[i+1]:
        count += 1
        S = H_lst[i+1]
print(count)