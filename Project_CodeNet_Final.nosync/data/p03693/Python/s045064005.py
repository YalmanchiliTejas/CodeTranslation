c = input().split()
print(['NO', 'YES'][int(c[1]+c[2]) % 4 is 0])
