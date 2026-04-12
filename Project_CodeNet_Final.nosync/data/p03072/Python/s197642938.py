n = int(input())
h = [int(i) for i in input().split()]
num_view = 1
for i in range(1,len(h)):
    h_max = max(h[:i])
    if h[i] >= h_max:
        num_view +=1
        
print(num_view)