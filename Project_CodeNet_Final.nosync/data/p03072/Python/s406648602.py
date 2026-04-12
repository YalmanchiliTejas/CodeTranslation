N = int(input())
N_lis = [int(i) for i in input().split()]
count,hi = 0,N_lis[0]
for i in N_lis:
        if hi <= i:
            count +=1
            hi = i

print(count)