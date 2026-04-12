
n = input()
n = int(n)
lst1 = input().split()

h_mtn = 0
count = 0

for i in range(0, n, 1):
    state = lst1[i]
    state = int(state)
    if state >= h_mtn:
        count += 1
    if state > h_mtn:
        h_mtn = state

print(count)