import sys
input = sys.stdin.readline
c = str(input()).rstrip()
v = ["a", "e", "i", "u", "o"]
if c == "a" or c == "e" or c == "i" or c == "u" or c == "o":
    print("vowel")
else:
    print("consonant")