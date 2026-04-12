n = int(input())
h_list = input().split(' ')
h_list = [int(h) for h in h_list]

score = 1

h1 = h_list[0]
max_h = h_list[0]
for i in range(1, n):
    h_i = h_list[i]
    if h_i >= h1 and h_i >= max_h:
        score += 1
        max_h = h_i
print(score)