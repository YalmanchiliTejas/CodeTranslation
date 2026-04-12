N = int(input())
line = list(map(int, input().split()))
a = 2*(10**9 +7)
total = sum(line)%a
output = total**2 %a
for i in range(N):
    output = (output - (line[i]**2)%a)%a
print( int(output/2))
