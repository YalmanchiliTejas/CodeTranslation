from re import sub

n = int(input())
s = input()
k = int(input())

print(sub('[^{}]'.format(s[k-1]), '*', s))
