import sys

vowel="aeiou"
if sys.stdin.readline()[0] in vowel:
    print "vowel"
else:
    print "consonant"