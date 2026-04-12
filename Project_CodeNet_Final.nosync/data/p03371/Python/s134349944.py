s = input().rstrip().split(' ')
costa = int(s[0])
costb = int(s[1])
costc = int(s[2])
needa = int(s[3])
needb = int(s[4])
mini = min(needa, needb)
maxi = max(needa, needb)
lst = []
total = costa * needa + costb * needb
totala = costa * needa + costb * needb
totalb = costc * maxi * 2
for i in range(mini+1):
  temp = costa * (needa - i) + costb * (needb - i) + costc * i * 2
  if total > temp:
    total = temp
lst.append(total)
lst.append(totala)
lst.append(totalb)
mintotal = min(lst)
print(mintotal)
