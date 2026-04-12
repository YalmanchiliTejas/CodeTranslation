N = int(input())
num_list = list(map(int,input().split()))
num_sum = []

joker = 0

for i in range(N):
    joker += num_list[i]

for i in range(N-1):
    joker -= num_list[i]
    num_sum.append(num_list[i]*joker)
    
print(sum(num_sum)%(10**9+7))