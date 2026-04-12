n = int(input())
c = list(map(int, input().split())) 

n_pos = 0
max_c = 0
for i in c:
    if i>=max_c:
        n_pos += 1
        max_c = i
    else:
        pass
print(n_pos)