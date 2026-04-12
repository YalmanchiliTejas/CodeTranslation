N = input()
H = map(int, raw_input().split())
maxt = 0
count = 0
for i in H:
	if(maxt <= i):
		maxt = i
		count = count + 1
print(count)