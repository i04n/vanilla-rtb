#!/bin/bash

output=`curl -X PUT -H "Content-Type: application/json" http://localhost:10081/cache_loader/geo 2> /dev/null`
output=`curl -X PUT -H "Content-Type: application/json" http://localhost:10081/cache_loader/geo_campaign 2> /dev/null`
output=`curl -X PUT -H "Content-Type: application/json" http://localhost:10081/cache_loader/ad 2> /dev/null`
output=`curl -X PUT -H "Content-Type: application/json" http://localhost:10081/cache_loader/budget 2> /dev/null`
#output=`curl -X PUT -H "Content-Type: application/json" http://localhost:10081/cache_loader/ 2> /dev/null`

echo $output

