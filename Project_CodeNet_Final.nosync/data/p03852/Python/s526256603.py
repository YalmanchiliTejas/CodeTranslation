#! /usr/bin/python3
# 居合を終え、青い絵を覆う / UOIAUAI
"""
英小文字 c が与えられるので、c が母音であるか判定してください。
ここで、英小文字のうち母音は a、e、i、o、uの 5 つです。
"""

c = input()

if c in ('a', 'i', 'u', 'e', 'o'):
    print('vowel')
else:
    print('consonant')
