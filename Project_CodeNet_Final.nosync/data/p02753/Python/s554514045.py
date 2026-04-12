s1, s2, s3 = input()
count = 0
if s1 != s2:
    count += 1
if s2 != s3:
    count += 1
if s1 != s3:
    count += 1
if count == 0:
    print('No')
else:
    print('Yes')