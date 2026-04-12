N = int(input())
H = map(int, input().split())

high = 0
score = 0
for value in H:
   if high <= value:
      high = value
      score += 1
      
print(score)