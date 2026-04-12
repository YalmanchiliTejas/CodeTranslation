import sys
readline = sys.stdin.buffer.readline

s = readline().rstrip().decode('utf-8')

class Judge():
    def __init__(self,s):
        self.s = s
        self.vowel = ["a","i","u","e","o"]
    def __call__(self):
        if self.s in self.vowel:
            print("vowel")
        else:
            print("consonant")

Judge(s)()
