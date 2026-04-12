N = int(input())

H = [int(i) for i in input().split()] 
counter = 0
standard = 0

for i in H:
  if i >= standard:
    standard = i
    counter += 1
    
print(counter)