N = int(input())
H = input().split()
H = [int(h) for h in H]

max_ = H[0]
count = 0

for i in range(N):
    if(H[i]>=max_):
        count += 1
    max_ = max([max_,H[i]])
    
print(count)