N = int(input())
H = list(map(int , input().split()))

can_see_ocean = 0

for i in range(N):
    compare_high = H[0:i+1]
    if max(compare_high) == H[i]:
        can_see_ocean += 1
        
print(can_see_ocean)