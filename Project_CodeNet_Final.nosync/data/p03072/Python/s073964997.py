N = int(input())
Hi = list(map(int,input().split()))

count = 0
done = [0]
for h in Hi:
  done.append(h)
  if h >= max(done):
    count+=1

print(count)