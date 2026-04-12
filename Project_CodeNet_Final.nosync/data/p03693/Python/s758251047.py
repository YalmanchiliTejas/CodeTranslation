# -*- coding: utf-8 -*-
rgb = int(input().replace(' ', ''))
print(['NO', 'YES'][rgb % 4 == 0])