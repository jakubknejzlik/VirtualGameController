Pod::Spec.new do |s|
s.name = 'VirtualGameController'
s.version = '0.0.5'
s.license = { :type => 'MIT', :file => 'LICENSE' }
s.summary = 'Feature-rich game controller framework for iOS, tvOS, OS X and watchOS in Swift 2.1.'

s.homepage = 'https://github.com/robreuss/VirtualGameController'
s.author = { 'tadija' => 'john.doe@example.com' }
s.social_media_url = 'http://twitter.com/john.doe'

s.source = { :git => 'https://github.com/robreuss/VirtualGameController.git', :tag => String(s.version) }
s.source_files = 'Source/**/*.swift'
s.ios.deployment_target = '9.0'
s.tvos.deployment_target = '9.0'
s.tvos.exclude_files = 'Source/**/VgcCentralPublisherWatch.swift'
s.osx.deployment_target = '10.10'
s.osx.exclude_files = ['Source/**/VgcCentralPublisherWatch.swift','Source/**/VgcCentralViewController.swift','Source/**/VgcSharedViews.swift','Source/**/VgcWatchConnectivity.swift']
end
