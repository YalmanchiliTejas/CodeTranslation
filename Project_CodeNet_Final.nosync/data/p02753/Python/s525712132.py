# coding: utf-8

s = raw_input()
print ['No', 'Yes'][len(set(s)) > 1]

