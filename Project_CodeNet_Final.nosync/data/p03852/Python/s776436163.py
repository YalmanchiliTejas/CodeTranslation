I = input()
import re
if re.match("^(a|i|u|e|o){1}$", I):
    print('vowel', flush=True)
else:
    print('consonant', flush=True)
