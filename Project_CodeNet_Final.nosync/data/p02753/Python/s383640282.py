N = input()
ans = 'Yes'
n0 = N[0]
count = 0
if N[0] == N[1]:
    count = count + 1
if N[1] == N[2]:
    count = count + 1
if N[0] == N[2]:
    count = count + 1
if count == 3:
    ans = 'No'
print(ans)