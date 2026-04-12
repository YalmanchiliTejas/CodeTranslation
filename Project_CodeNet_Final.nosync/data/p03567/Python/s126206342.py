S = raw_input()
def test():
    for i in range(len(S)-1):
        if S[i:i+2] == "AC":
            return 1
    return 0

print "Yes" if test() else "No"
