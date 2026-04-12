N = int(input())
H_list = list(map(int, input().split()))


ans = 0
highest = -1
for h in H_list:
    if highest <= h:
        ans +=1
        highest = h
    else:
        pass
    
print(ans)