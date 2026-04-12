# python3 (3.4.3)
import sys
input = sys.stdin.readline

# main
c = input().rstrip()

print("vowel" if c in "aiueo" else "consonant")