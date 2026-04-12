n = int(input())
a = list(map(int, input().split()))

necessary_height = a[0]
answer = 0
for i in range(n):
  if (a[i] >= necessary_height):
    answer += 1
    necessary_height = a[i]
    
print(answer)