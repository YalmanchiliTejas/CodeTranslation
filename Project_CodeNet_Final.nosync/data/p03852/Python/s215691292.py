import sys
input = sys.stdin.readline().strip
c=list(input().strip())
b=["a","i","u","e","o"]
flg=True
for i in c:
    if i not in b:
        flg=False
print("vowel" if flg else "consonant")
