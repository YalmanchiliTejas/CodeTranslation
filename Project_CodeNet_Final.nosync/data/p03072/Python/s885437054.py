N = int(input())
hotel = list(map(int,input().split()))
new =[]

count = 0
for i in hotel:
  new.append(i)
  if i == max(new):
    count += 1
print(count)
