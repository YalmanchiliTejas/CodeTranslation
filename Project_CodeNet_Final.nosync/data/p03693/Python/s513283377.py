array = input().split()
score = int(array[1]) * 10 + int(array[2])
if score % 4 == 0:
   print("YES")
else:
    print("NO")