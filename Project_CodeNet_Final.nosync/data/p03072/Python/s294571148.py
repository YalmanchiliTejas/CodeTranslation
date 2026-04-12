length = int(raw_input())
M = map(int, raw_input().split())

count = 0
h = 0

for m in M:
    if int(m) >= h:
        count = count + 1
        h = m 
print(count)

        
